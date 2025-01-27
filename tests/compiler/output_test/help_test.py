

import os
import shlex
import subprocess
from colorama import Fore, Style

from compiler.test_res import success, add_failed_test
from compiler.util import test_report_compare


def test_help(dap_main, source_runtime_dir, D_DEBUG = False, debug_mode = False):
    print(Fore.BLUE + "Testing help command" + Style.RESET_ALL)
    result = subprocess.run(dap_main + " -h",  capture_output=True, text=True, shell=True)

    if D_DEBUG :
        test_report_compare(result, "help", "Help command",
                            """
Usage:  [-h] [-d <directory>] [-D] [-i] [-e] [-o <output_directory>] [-n <executable_name>]
  -h, --help            Show this help message and exit
  -d, --directory       Compile the specified directory
  -D, --debug           Enable debug mode
  -i, --generate-ir     Generate LLVM IR
  -e, --generate-exec   Generate executable
  -v, --version         Print version information and exit
  -o, --output          Specify the output directory
  -n, --output-exec-name Specify the name of the generated executable
  -s, --source-runtime-dir Source directory of runtime
""")
    else:
        test_report_compare(result, "help", "Help command",
                            """
Usage:  [-h] [-d <directory>] [-D] [-i] [-e] [-o <output_directory>] [-n <executable_name>]
  -h, --help            Show this help message and exit
  -d, --directory       Compile the specified directory
  -D, --debug           Enable debug mode
  -i, --generate-ir     Generate LLVM IR
  -e, --generate-exec   Generate executable
  -v, --version         Print version information and exit
  -o, --output          Specify the output directory
  -n, --output-exec-name Specify the name of the generated executable
""")
        

        