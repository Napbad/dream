#include <fstream>
#include <getopt.h>
#include <iostream>
#include <llvm/Bitstream/BitstreamReader.h>

#include "common/config.h"
#include "inter_gen/preprocessing/includeAnaylize.h"
#include "machine_gen/codeGen_mechine.h"
#include "parser/parserMain.h"
#include "utilities/file_util.h"
#include "utilities/log_util.h"
#include "utilities/obj_util.h"

namespace dap::inter_gen
{
extern llvm::LLVMContext *llvmContext;
}

using std::cerr;
using std::cout;
using std::endl;
using std::string;

#ifdef D_DEBUG
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

bool checkInputPathValidWithRemind(const std::string &inputPath);

struct CompilerOptions {
    std::string inputPath;
    std::vector<std::string> inputFiles;
    std::string sourceRuntimeDir = "../../dap/runtime/";
    bool debugMode = false;
    bool compileDir = false;
    bool helpRequested = false;
    bool genIR = false;
    bool genExec = false;
    std::string buildDir = "./build/";
    std::string targetExecName;

    bool valid = true;
};

CompilerOptions parseOptions(int argc, char **argv);

int main(const int argc, char **argv)
{
    dap::buildDir = "./build/";
    int opt;

    CompilerOptions options = parseOptions(argc, argv);

    if (!options.valid) {
        return 0;
    }

    // Collect non-option arguments as input files
    for (int i = optind; i < argc; ++i) {
        options.inputFiles.emplace_back(argv[i]);
    }

    if (options.helpRequested) {
        dap::util::printHelpMsg();
        return 0;
    }

    // no input, just return
    if (!checkInputPathValidWithRemind(options.inputPath)) {
        return 1;
    }

    dap::initCompiler(dap::inter_gen::llvmContext);
    dap::util::delete_directory(dap::buildDir);

#ifdef D_DEBUG
    dap::util::copy_directory(options.sourceRuntimeDir + "asm", dap::buildDir + "dap/runtime/asm");
#else
    dap::util::copy_directory("../../dap/runtime/asm", dap::buildDir + "dap/runtime/asm");
#endif

    if (options.compileDir) {
        std::vector<std::string> files = dap::util::get_all_files_in_dir(options.inputPath);
        for (const auto &file : files) {
            if (!file.ends_with(".dap")) {
                continue;
            }
            dap::parser::parseFile(file);
#ifdef D_DEBUG
            // LOG_DEBUG("\n\n====current parsing====");
            // std::string info = "Parsing file: " + file;
            // LOG_DEBUG(info);
#endif
            // dap::parser::parseFile(file);
        }

        const auto includeAnalyzer = new dap::inter_gen::IncludeAnalyzer();
        includeAnalyzer->generateGraph();
        const std::set<dap::inter_gen::IncludeGraphNode *> roots = includeAnalyzer->getRoots();
        if (options.genIR) {
            interGen(roots);
        } else {
            dap::mech_gen::execGen(roots);
        }
    } else {
        std::pair<dap::parser::ProgramNode *, dap::inter_gen::InterGenContext *> pair;
        for (auto &file : options.inputFiles) {
            pair = dap::parser::parseFile(file);
        }

        if (options.genIR) {
            pair.second->genIR(program);
        }
        else {
            dap::mech_gen::execGen_singleFile(pair.second, program);
        }
    }

    dap::util::deleteDelayedObj();
    return 0;
}

bool checkInputPathValidWithRemind(const std::string &inputPath)
{
    if (!inputPath.empty()) {
        std::ifstream infileOrDir;
        infileOrDir.open(inputPath);
        if (!infileOrDir.is_open()) {
            dap::util::printHelpMsg();
            return false;
        }
    }
    return true;
}

CompilerOptions parseOptions(const int argc, char **argv)
{
    CompilerOptions options;
    int opt;
    while ((opt = getopt_long(argc, argv, "n:d:o:ievhDs:", long_options, nullptr)) != -1) {
        switch (opt) {
        case 'h':
            options.helpRequested = true;
            break;
        case 'd':
            if (optarg == nullptr) {
                cerr << "Error: Missing argument for option -d" << endl;
                options.valid = false;
                return options;
            }
            options.inputPath = optarg;
            options.compileDir = true;
            break;
        case 'D':
            options.debugMode = true;
            break;
        case 'i':
            options.genIR = true;
            break;
        case 'e':
            options.genExec = true;
            break;
        case 'v':
            std::cout << "dap version: " << dap::D_VERSION << std::endl;
            options.valid = false;
            return options;
        case 'o':
            if (optarg == nullptr) {
                cerr << "Error: Missing argument for option -o" << endl;
                options.valid = false;
                return options;
            }
            options.buildDir = optarg;
            if (!options.buildDir.ends_with("/")) {
                options.buildDir.append("/");
            }
            break;
        case 'n':
            if (optarg == nullptr) {
                cerr << "Error: Missing argument for option -n" << endl;
                options.valid = false;
                return options;
            }
            options.targetExecName = optarg;
            break;
#ifdef D_DEBUG
        case 's':
            if (optarg == nullptr) {
                cerr << "Error: Missing argument for option -s" << endl;
                options.valid = false;
                return options;
            }
            options.sourceRuntimeDir = optarg;
            if (!options.sourceRuntimeDir.ends_with("/")) {
                options.sourceRuntimeDir.append("/");
            }
            break;
#endif
        default:
            std::cerr << "Invalid option: " << static_cast<char>(opt) << std::endl;
            std::cout << "Usage: " << argv[0]
                      << " [-h] [-d <directory>] [-D] [-i] [-e] [-o <output_directory>] [-n <executable_name>]"
                      << std::endl;
            options.valid = false;
            return options;
        }
    }

    dap::buildDir = options.buildDir;
    dap::targetExecName = options.targetExecName;

    return options;
}