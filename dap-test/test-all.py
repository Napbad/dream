import argparse
import subprocess
from _ast import pattern

# Create a parser object
parser = argparse.ArgumentParser(description='A sample script to execute different commands')

# Add command line arguments
parser.add_argument('command', type=str, help='The command to execute, options include list, find, etc.')
parser.add_argument('-f', '--file-pattern', type=str, default='*.txt', help='File pattern for searching files, default is *.txt')

# Parse command line arguments
args = parser.parse_args()

if args.command == "list":
    command = "ls"  # For Windows systems, you can use "dir"
    result = subprocess.run(command, shell=True, capture_output=True, text=True)
    if result.returncode == 0:
        print(result.stdout)
    else:
        print(f"Executing command {command} failed, error message: {result.stderr}")
elif args.command == "find":
    command = f"find . -name '{args.file-pattern}'"
    result = subprocess.run(command, shell=True, capture_output=True, text=True)
    if result.returncode == 0:
        print(result.stdout)
    else:
        print(f"Executing command {command} failed, error message: {result.stderr}")
else:
    print("Unsupported command, please enter the correct command parameter")
