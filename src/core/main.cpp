#include "common/define_d.h"
#include "common/global.h"

#include <getopt.h>
#include <iostream>

#include "inter_gen/codegen_inter.h"
#include "inter_gen/preprocessing/includeAnaylize.h"
#include "mechine_code_gen/codeGen_mechine.h"
#include "parser/node.h"
#include "parser/parser.hpp"
#include "utilities/file_util.h"
#include "utilities/obj_util.h"

#include "llvm/Pass.h"
#include <llvm/Bitstream/BitstreamReader.h>
#include <llvm/Support/TargetSelect.h>

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
    int opt;
    bool debugMode = false;
    bool compileDir = false;
    bool helpRequested = false;
    bool genIR = false;
    bool genExec = false;
    string inputPath;

    static option long_options[] = {{"help", no_argument, nullptr, 'h'},
                                    {"directory", required_argument, nullptr, 'd'},
                                    {"debug", no_argument, nullptr, 'D'},
                                    {"generate-ir", no_argument, nullptr, 'i'},
                                    {"generate-exec", no_argument, nullptr, 'e'},
                                    {"version", no_argument, nullptr, 'v'},
                                    {nullptr, 0, nullptr, 0}};

    while ((opt = getopt_long(argc, argv, "hd:Die", long_options, nullptr)) != -1)
    {
        switch (opt)
        {
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
        default:
            cerr << "Usage: " << argv[0] << " [-h] [-d <directory>] [-D] [-i] [-e]" << endl;
            return 1;
        }
    }

    if (helpRequested)
    {
        cout << "Usage: " << argv[0] << " [-h] [-d <directory>] [-D]" << endl;
        cout << "  -h, --help            Show this help message and exit" << endl;
        cout << "  -d, --directory       Compile the specified directory" << endl;
        cout << "  -D, --debug           Enable debug mode" << endl;
        cout << "  -i, --generate IR     Generate LLVM IR" << endl;
        cout << "  -e, --generate Exec   Generate executable" << endl;
        cout << "  -v, --version         Print version information and exit" << endl;
        return 0;
    }

    if (debugMode)
    {
#ifdef D_DEBUG
        dbg_print(cout, "====== DEBUG MODE IS ON ======\n", dap::util::FileColor::BRIGHT_MAGENTA);
#endif
    }

    if (optind < argc)
    {
        inputPath = argv[optind];
    }
    else if (inputPath.empty())
    {
        inputPath = "main.drm";
    }

    InitializeAllTargetInfos();
    InitializeAllTargets();
    InitializeAllTargetMCs();
    InitializeAllAsmParsers();
    InitializeAllAsmPrinters();

    if (!inputPath.empty())
    {
        ifstream infileOrDir;
        infileOrDir.open(inputPath);
        if (!infileOrDir.is_open())
        {
            cerr << "Error: Unable to open file or directory: " << inputPath << endl;
            return 1;
        }
    }

    util::delete_directory("./build");

    if (compileDir)
    {
        std::vector<std::string> files = util::get_all_files_in_dir(inputPath);
        for (const auto &file : files)
        {
            if (!file.ends_with(".drm"))
            {
                continue;
            }
#ifdef D_DEBUG
            std::string info = "Parsing file: " + file;
            LOG_DEBUG(info);
#endif
            yyrestart(fopen(file.c_str(), "r"));
            yylineno = 1;
            program = nullptr;
            openFile(file.c_str());
            auto *ctx = new inter_gen::InterGenContext(file);
            yyparse();
            programMap_d->insert({program, ctx});
        }

        util::copy_directory("../src/dap/runtime/asm", "./build/dap/runtime/asm");
        auto includeAnalyzer = new dap::inter_gen::IncludeAnalyzer();
        includeAnalyzer->generateGraph();
        std::set<inter_gen::IncludeGraphNode *> roots = includeAnalyzer->getRoots();
        if (genIR)
        {
            interGen(roots);
        }
        else
        {
            mech_gen::execGen(roots);
        }
    }
    else
    {
        if (argc > 1)
        {
            openFile(inputPath.c_str());
        }
        auto *ctx = new inter_gen::InterGenContext(inputPath);
        yyparse();

        ctx->genIR(program);
    }

    obj_util::deleteDelayedObj();
    return 0;
}