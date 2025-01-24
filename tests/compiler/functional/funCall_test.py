import os.path
import subprocess
from pathlib import Path

from colorama import Fore, Style

from compiler.test_res import failedTest, success, add_failed_test
from compiler.util import build_executable_file_command, test_report_default, run_executable_target


def testFunCall(dap_main, source_runtime_dir, d_debug = False):
    arg = ""
    script_path = Path(__file__).resolve()
    script_dir = script_path.parent
    dap_file = script_dir / "funCall_test.dap"

    # Correct the command list by removing the extra spaces around -s
    command_list = build_executable_file_command(dap_main, dap_file)
    result = subprocess.run(command_list, capture_output=True, text=True)

    print(Fore.BLUE + "Testing: ./functional/funCall_test.dap")

    print(command_list)

    if result.returncode != 0:
        print(Fore.RED + "Error: " + Style.RESET_ALL + result.stderr)
        add_failed_test(dap_file)
        return

    target_run_result = subprocess.run(run_executable_target(), capture_output=True, text=True)

    if target_run_result.returncode != 0:
        print(Fore.RED + "Error: " + Style.RESET_ALL + target_run_result.stderr)
        print(Fore.RED + "Error: " + Style.RESET_ALL + target_run_result.stdout)
        add_failed_test(dap_file)
        return
    else:
        if not target_run_result.stdout.__contains__("Hello world!"):
            add_failed_test(dap_file)
        else:
            success()
    if d_debug:
        print(Fore.RED + result.stderr + Style.RESET_ALL)
        print(Fore.GREEN + result.stdout + Style.RESET_ALL)

    # test_report_default(result, dap_file, "function call")
