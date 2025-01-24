import argparse
import os.path

from functional.testFunctional import testFunctional
from syntax.test_syntax import test_syntax
from test_res import print_result
from config import parse_config
from output_test.output_test import test_output
from util import get_dap_files
from colorama import init, Fore, Style

# Initialize colorama
init(autoreset=True)

config = parse_config()

# Create a parser object
parser = argparse.ArgumentParser(description='A sample script to execute different commands')

# # Add command line arguments
# parser.add_argument('command', type=str, help='The command to execute, options include list, find, etc.')
# parser.add_argument('-d', '--directory', type=str, default='./', help='Directory to tests')
# parser.add_argument('-s', '--source-runtime-dir', type=str, default='./', help='Source runtime directory')

# Parse command line arguments
# args = parser.parse_args()

# get the value of dap executable path
project_path = config.get("dap", {}).get("project-path")

D_debug = config.get("dap", {}).get("test", {}).get("D_DEBUG")


dap_main = project_path + config.get("dap", {}).get("test", {}).get("dap-main-path")
directory = project_path + config.get("dap", {}).get("test", {}).get("target-directory")
source_runtime_dir = project_path + config.get("dap", {}).get("test", {}).get("source-runtime-dir")


if D_debug is None:
    D_debug = False
    print(Fore.YELLOW + "D_DEBUG is not set, default value is False" + Style.RESET_ALL)
else:
    print(Fore.BLUE + f"D_DEBUG is set to {D_debug}" + Style.RESET_ALL)
    if D_debug is True:
        print(Fore.YELLOW + "D_DEBUG is set to True, will print debug information" + Style.RESET_ALL)
        print(Fore.BLUE + f"dap_main:            {dap_main}" + Style.RESET_ALL)
        print(Fore.BLUE + f"project_path:        {project_path}" + Style.RESET_ALL)
        print(Fore.BLUE + f"directory:           {directory}" + Style.RESET_ALL)
        print(Fore.BLUE + f"source_runtime_dir:  {source_runtime_dir}" + Style.RESET_ALL)
        print(Fore.BLUE + f"Dap executable file: {dap_main}" + Style.RESET_ALL)
        print("\n")


source_runtime_dir = os.path.abspath(source_runtime_dir)


dap_files = get_dap_files(directory)

print(Fore.CYAN + "Dap files to be tests:" + Style.RESET_ALL)
for file in dap_files:
    print(Fore.LIGHTMAGENTA_EX + "  " + file + Style.RESET_ALL)

print("\n")

test_syntax(dap_main, source_runtime_dir, D_debug)
testFunctional(dap_main, source_runtime_dir, D_debug)
# test_functional(dap_main, source_runtime_dir, D_debug)
# test_control(dap_main, source_runtime_dir, D_debug)
test_output(dap_main, source_runtime_dir, D_debug)

print_result()