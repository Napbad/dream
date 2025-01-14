//
// Created by napbad on 1/9/25.
//
#include <fstream>
#include <getopt.h>
#include <iostream>

#include <llvm/Bitstream/BitstreamReader.h>
#include <llvm/Pass.h>
#include <llvm/Support/TargetSelect.h>

#include "common/config.h"
#include "parser/parserMain.h"
#include "utilities/file_util.h"
#include "utilities/log_util.h"
#include "utilities/obj_util.h"

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

int main(const int argc, char **argv)
{
    dap::buildDir = "./build/";
    int opt;
    bool debugMode = false;
    bool compileDir = false;
    bool helpRequested = false;
    bool genIR = false;
    bool genExec = false;
    string inputPath;
    std::vector<std::string> inputFiles;
    std::string sourceRuntimeDir = "../../dap/runtime/";

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
            cout << "dap version: " << dap::D_VERSION << endl;
            return 0;
        case 'o':
            dap::buildDir = optarg;
            if (!dap::buildDir.ends_with("/")) {
                dap::buildDir.append("/");
            }
            break;
        case 'n':
            dap::targetExecName = optarg;
            break;

#ifdef D_DEBUG
        case 's':
            sourceRuntimeDir = optarg;
            break;
#endif

        default:
            cerr << "Invalid option: " << static_cast<char>(opt) << endl;
            cout << "Usage: " << argv[0]
                 << " [-h] [-d <directory>] [-D] [-i] [-e] [-o <output_directory>] [-n <executable_name>]" << endl;
            return 1;
        }
    }

    // Collect non-option arguments as input files
    for (int i = optind; i < argc; ++i) {
        inputFiles.push_back(argv[i]);
    }

    if (helpRequested) {
        dap::util::printHelpMsg();
    }

    // no input, just return
    if (!checkInputPathValidWithRemind(inputPath)) {
        return 1;
    }

    llvm::InitializeAllTargetInfos();
    llvm::InitializeAllTargets();
    llvm::InitializeAllTargetMCs();
    llvm::InitializeAllAsmParsers();
    llvm::InitializeAllAsmPrinters();

    dap::util::delete_directory(dap::buildDir);

    if (compileDir) {
        std::vector<std::string> files = dap::util::get_all_files_in_dir(inputPath);
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
            // yyrestart(fopen(file.c_str(), "r"));
            // yylineno = 1;
            // program = nullptr;
            // openFile(file.c_str());
            // auto *ctx = new inter_gen::InterGenContext(file);
            // yyparse();
            // // store the parser result and the context
            // programMap_d->insert({program, ctx});
        }

#ifdef D_DEBUG
        dap::util::copy_directory(sourceRuntimeDir + "asm", dap::buildDir + "dap/runtime/asm");
#else
        dap::util::copy_directory("../src/dap/runtime/asm", dap::buildDir + "dap/runtime/asm");

#endif

        // auto includeAnalyzer = new dap::inter_gen::IncludeAnalyzer();
        // includeAnalyzer->generateGraph();
        // std::set<inter_gen::IncludeGraphNode *> roots = includeAnalyzer->getRoots();
        // if (genIR)
        // {
        //     interGen(roots);
        // }
        // else
        // {
        //     mech_gen::execGen(roots);
        // }
    } else {
        for (auto &file : inputFiles) {
            auto *ctx = new dap::inter_gen::InterGenContext(inputPath);
            dap::parser::parseFile(file);
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