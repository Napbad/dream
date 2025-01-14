

import os
import subprocess
from colorama import Fore, Style

from test_res import add_failed_test, success


def test_help(dap_main, source_runtime_dir, D_DEBUG = False):
    print(Fore.BLUE + "Testing help command" + Style.RESET_ALL)
    result = subprocess.run([dap_main, "-h"],  capture_output=True, text=True)
    if result.returncode == 0:

        if D_DEBUG:
            if result.stdout.__contains__("""Usage:  [-h] [-d <directory>] [-D] [-i] [-e] [-o <output_directory>] [-n <executable_name>]
  -h, --help            Show this help message and exit
  -d, --directory       Compile the specified directory
  -D, --debug           Enable debug mode
  -i, --generate-ir     Generate LLVM IR
  -e, --generate-exec   Generate executable
  -v, --version         Print version information and exit
  -o, --output          Specify the output directory
  -n, --output-exec-name Specify the name of the generated executable
  -s, --source-runtime-dir Source directory of runtime""") :

                print(Fore.GREEN + "Help command PASSED!" + Style.RESET_ALL)
                success()
            else:
                print(Fore.RED + "Help command FAILED" + Style.RESET_ALL)   
                print(Fore.RED + result.stderr + Style.RESET_ALL)
                print(Fore.RED + result.stdout + Style.RESET_ALL)
                add_failed_test(Fore.BLUE + "<Help command> " + Fore.RED + "[failed] " +  Fore.CYAN + " path: " + os.path.abspath(__file__))
        else:
            if result.stdout.__contains__("""Usage:  [-h] [-d <directory>] [-D] [-i] [-e] [-o <output_directory>] [-n <executable_name>]
  -h, --help            Show this help message and exit
  -d, --directory       Compile the specified directory
  -D, --debug           Enable debug mode
  -i, --generate-ir     Generate LLVM IR
  -e, --generate-exec   Generate executable
  -v, --version         Print version information and exit
  -o, --output          Specify the output directory
  -n, --output-exec-name Specify the name of the generated executable
  -s, --source-runtime-dir Source directory of runtime""") :
                success()

                print(Fore.GREEN + "Help command PASSED!" + Style.RESET_ALL)
            
            else:
                print(Fore.RED + "Help command FAILED" + Style.RESET_ALL)   
                print(Fore.RED + result.stderr + Style.RESET_ALL)
                print(Fore.RED + result.stdout + Style.RESET_ALL)

                add_failed_test(Fore.BLUE + "<Help command> " + Fore.RED + "[failed] " +  Fore.CYAN + " path: " + os.path.abspath(__file__))

    else:
        print(Fore.RED + "Help command FAILED" + Style.RESET_ALL)
        print(Fore.RED + result.stderr + Style.RESET_ALL)
        print(Fore.RED + result.stdout + Style.RESET_ALL)
        