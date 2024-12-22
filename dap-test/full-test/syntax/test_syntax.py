import os.path
import subprocess
from pathlib import Path

from colorama import Fore, Style

from util import get_dap_files


def test_syntax(dap_main, source_runtime_dir, d_debug = False):
    arg = " -i"
    """
    Test the syntax of the code.
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
        if dap_file.__contains__("mutable_test.dap"):
            if not (result.stderr.__contains__("can not assign to a immutable value: a ")):
                print(Fore.RED, "FAIL: with" , result.args, "\nexpect in stderr:" + "can not assign to a immutable value: a " + Style.RESET_ALL)
                print(Fore.YELLOW + "stderr:" + Style.RESET_ALL)
                print(Fore.YELLOW + result.stderr + Style.RESET_ALL)
            else:
                print(Fore.GREEN + "PASS!" + Style.RESET_ALL)
        elif dap_file.__contains__("nullable_test.dap"):
            if not (result.stderr.__contains__("can not assign a nullable value to a non-nullable value:")):
                print(Fore.RED, "FAIL: with" , result.args, "\nexpect in stderr:" + "can not assign a nullable value to a non-nullable value:" + Style.RESET_ALL)
                print(Fore.YELLOW + "stderr:" + Style.RESET_ALL)
                print(Fore.YELLOW + result.stderr + Style.RESET_ALL)
            else:
                print(Fore.GREEN + "PASS!" + Style.RESET_ALL)
        elif dap_file.__contains__("type_base_test.dap"):

            if result.stderr.__contains__("error") or result.stderr.__contains__("warning") or result.stderr.__contains__("Error"):
                print(Fore.RED, "FAIL: with" , result.args, "\nexpect no error in stderr" + Style.RESET_ALL)
                print(Fore.YELLOW + "stderr:" + Style.RESET_ALL)
                print(Fore.YELLOW + result.stderr + Style.RESET_ALL)

                print(Fore.YELLOW + "stdout:" + Style.RESET_ALL)
                print(Fore.YELLOW + result.stdout + Style.RESET_ALL)

            else:
                print(Fore.GREEN + "PASS" + Style.RESET_ALL)