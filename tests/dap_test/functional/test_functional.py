import os.path
import subprocess
from pathlib import Path

from colorama import Fore, Style

from test_res import success
from util import get_dap_files


def test_functional(dap_main, source_runtime_dir, d_debug = False):
    arg = " -i"
    """
    Test the functional of the code.
    """
    dap_files_to_test = get_dap_files("./")
    for dap_file in dap_files_to_test:
        # Correct the command list by removing the extra spaces around -s
        command_list = [
            Path(os.path.abspath(dap_main)).__str__(),
            "-s",
            source_runtime_dir,
            os.path.abspath(dap_file),
            arg.strip()  # Also remove any extra spaces from the arg if present
        ]
        result = subprocess.run(command_list, capture_output=True, text=True)

        print(Fore.BLUE + f"Executing: {dap_file} {arg}" + Style.RESET_ALL)
        print(result.args)


        if d_debug:
            print(Fore.RED + result.stderr + Style.RESET_ALL)
            print(Fore.GREEN + result.stdout + Style.RESET_ALL)
        success()