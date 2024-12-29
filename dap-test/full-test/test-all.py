import argparse
import os.path
import subprocess
from _ast import pattern

from control.test_control import test_control
from functional.test_functional import test_functional
from syntax.test_syntax import test_syntax
from test_res import print_result
from util import get_dap_files
from colorama import init, Fore, Style

# Initialize colorama
init(autoreset=True)

# Create a parser object
parser = argparse.ArgumentParser(description='A sample script to execute different commands')

# Add command line arguments
parser.add_argument('command', type=str, help='The command to execute, options include list, find, etc.')
parser.add_argument('-d', '--directory', type=str, default='./', help='Directory to test')
parser.add_argument('-s', '--source-runtime-dir', type=str, default='./', help='Source runtime directory')

# Parse command line arguments
args = parser.parse_args()

# get the value of dap executable path
dap_main = args.command
directory = args.directory
source_runtime_dir = args.source_runtime_dir

source_runtime_dir = os.path.abspath(source_runtime_dir)

print(Fore.BLUE + f"Dap executable file: {dap_main}" + Style.RESET_ALL)

dap_files = get_dap_files(directory)

print(Fore.CYAN + "Dap files to be test:" + Style.RESET_ALL)
for file in dap_files:
    print(Fore.LIGHTMAGENTA_EX + file + Style.RESET_ALL)


test_syntax(dap_main, source_runtime_dir)
test_functional(dap_main, source_runtime_dir)
test_control(dap_main, source_runtime_dir)

print_result()