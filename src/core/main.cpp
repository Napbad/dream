

#include <getopt.h>
#include <iostream>
#include <llvm/Bitstream/BitstreamReader.h>
#include <llvm/Pass.h>
#include <llvm/Support/TargetSelect.h>

#include "src/core/common/define_d.h"
#include "src/core/common/global.h"
#include "src/core/inter_gen/codegen_inter.h"
#include "src/core/inter_gen/preprocessing/includeAnaylize.h"
#include "src/core/mechine_code_gen/codeGen_mechine.h"
#include "src/core/parser/node.h"
#include "src/core/parser/parser.hpp"
#include "src/core/utilities/file_util.h"
#include "src/core/utilities/obj_util.h"

using namespace std;
extern dap::parser::Program *program;
using namespace dap;

void openFile(const char *filename)
{
    freopen(filename, "r", stdin);
}

extern void yyrestart(FILE *input_file);

extern int yylineno;

int main(const int argc, char **argv)
{
    buildDir = "./build/";
    int opt;
    bool debugMode = false;
    bool compileDir = false;
    bool helpRequested = false;
    bool genIR = false;
    bool genExec = false;
    string inputPath;

#ifdef D_DEBUG
    if (debugMode) {
        dbg_print(cout, "====== DEBUG MODE IS ON ======\n", dap::util::FileColor::BRIGHT_MAGENTA);
    }

    static option long_options[] = {{"help", no_argument, nullptr, 'h'},
                                    {"directory", required_argument, nullptr, 'd'},
                                    {"debug", no_argument, nullptr, 'D'},
                                    {"generate-ir", no_argument, nullptr, 'i'},
                                    {"generate-exec", no_argument, nullptr, 'e'},
                                    {"version", no_argument, nullptr, 'v'},
                                    {"output", required_argument, nullptr, 'o'},
                                    {"output-exec-name", required_argument, nullptr, 'n'},
                                    {"source-runtime-dir", required_argument, nullptr, 's'},
                                    {nullptr, 0, nullptr, 0}};
    std::string sourceRuntimeDir;
#else

    static option long_options[] = {{"help", no_argument, nullptr, 'h'},
                                    {"directory", required_argument, nullptr, 'd'},
                                    {"debug", no_argument, nullptr, 'D'},
                                    {"generate-ir", no_argument, nullptr, 'i'},
                                    {"generate-exec", no_argument, nullptr, 'e'},
                                    {"version", no_argument, nullptr, 'v'},
                                    {"output", required_argument, nullptr, 'o'},
                                    {"output-exec-name", required_argument, nullptr, 'n'},
                                    {nullptr, 0, nullptr, 0}};

#endif 


    while ((opt = getopt_long(argc, argv, "n:d:o:ievhDs:", long_options, nullptr)) != -1) {
        switch (opt) {
        case 'h':
            helpRequested = true;
            break;
        case 'd':
            inputPath = optarg;
            compileDir = true;
            break;
        case 'D':
            debugMode = true;
            break;
        case 'i':
            genIR = true;
            break;
        case 'e':
            genExec = true;
            break;
        case 'v':
            cout << "dap version: " << D_VERSION << endl;
            break;
        case 'o':
            buildDir = optarg;
            if (!buildDir.ends_with("/")) {
                buildDir.append("/");
            }
            break;
        case 'n':
            targetExecName = optarg;
            break;

#ifdef D_DEBUG
        case 's':
            sourceRuntimeDir = optarg;
            break;
#endif

        default:
            cerr << "Invalid option: " << static_cast<char>(opt) << endl;
            cerr << "Usage: " << argv[0]
                 << " [-h] [-d <directory>] [-D] [-i] [-e] [-o <output_directory>] [-n <executable_name>]" << endl;
            return 1;
        }
    }

    if (helpRequested) {
        cout << "Usage: " << argv[0]
             << " [-h] [-d <directory>] [-D] [-i] [-e] [-o <output_directory>] [-n <executable_name>]" << endl;
        cout << "  -h, --help            Show this help message and exit" << endl;
        cout << "  -d, --directory       Compile the specified directory" << endl;
        cout << "  -D, --debug           Enable debug mode" << endl;
        cout << "  -i, --generate-ir     Generate LLVM IR" << endl;
        cout << "  -e, --generate-exec   Generate executable" << endl;
        cout << "  -v, --version         Print version information and exit" << endl;
        cout << "  -o, --output          Specify the output directory" << endl;
        cout << "  -n, --output-exec-name Specify the name of the generated executable" << endl;
        #ifdef D_DEBUG
        cout << "  -s, --source-runtime-dir Source directory of runtime" << endl;
        #endif
        return 0;
    }

    if (debugMode) {
#ifdef D_DEBUG
        dbg_print(cout, "====== DEBUG MODE IS ON ======\n", dap::util::FileColor::BRIGHT_MAGENTA);
#endif
    }

    if (optind < argc) {
        inputPath = argv[optind];
    } else if (inputPath.empty()) {
        inputPath = "main.dap";
    }

    InitializeAllTargetInfos();
    InitializeAllTargets();
    InitializeAllTargetMCs();
    InitializeAllAsmParsers();
    InitializeAllAsmPrinters();

    if (!inputPath.empty()) {
        ifstream infileOrDir;
        infileOrDir.open(inputPath);
        if (!infileOrDir.is_open()) {
            cerr << "Error: Unable to open file or directory: " << inputPath << endl;
            return 1;
        }
    }

    util::delete_directory(buildDir);

    if (compileDir) {
        std::vector<std::string> files = util::get_all_files_in_dir(inputPath);
        for (const auto &file : files) {
            if (!file.ends_with(".dap")) {
                continue;
            }
#ifdef D_DEBUG
            LOG_DEBUG("\n\n====current parsing====");
            std::string info = "Parsing file: " + file;
            LOG_DEBUG(info);
#endif
            yyrestart(fopen(file.c_str(), "r"));
            yylineno = 1;
            program = nullptr;
            openFile(file.c_str());
            auto *ctx = new inter_gen::InterGenContext(file);
            yyparse();
            // store the parser result and the context
            programMap_d->insert({program, ctx});
        }

#ifdef D_DEBUG
        util::copy_directory(sourceRuntimeDir + "/asm", buildDir + "dap/runtime/asm");
#else 
        util::copy_directory("../src/dap/runtime/asm", buildDir + "dap/runtime/asm");

#endif

        
        auto includeAnalyzer = new dap::inter_gen::IncludeAnalyzer();
        includeAnalyzer->generateGraph();
        std::set<inter_gen::IncludeGraphNode *> roots = includeAnalyzer->getRoots();
        if (genIR) {
            interGen(roots);
        } else {
            mech_gen::execGen(roots);
        }
    } else {
        if (argc > 1) {
            openFile(inputPath.c_str());
        }

#ifdef D_DEBUG
        util::copy_directory(sourceRuntimeDir + "/asm", buildDir + "dap/runtime/asm");
#else 
        util::copy_directory("../src/dap/runtime/asm", buildDir + "dap/runtime/asm");

#endif
        auto *ctx = new inter_gen::InterGenContext(inputPath);
        yyparse();

        if (genIR)
            ctx->genIR(program);
        else {
            mech_gen::execGen_singleFile(ctx, program);
        }
    }

    obj_util::deleteDelayedObj();
    return 0;
}