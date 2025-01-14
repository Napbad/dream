import os.path
import subprocess
from pathlib import Path

from colorama import Fore, Style

from test_res import success, add_failed_test
from util import get_dap_files


def testBasicTypeDefine(dap_main, source_runtime_dir, d_debug = False):
    arg = ""

    dap_file = "./syntax/basicTypeDefine_test.dap"
    # Correct the command list by removing the extra spaces around -s
    command_list = [
        Path(os.path.abspath(dap_main)).__str__(),
        "-s",
        source_runtime_dir,
        os.path.abspath(dap_file),
        arg.strip()  # Also remove any extra spaces from the arg if present
    ]
    result = subprocess.run(command_list, capture_output=True, text=True)

    print(Fore.BLUE + f"Testing: {dap_file}" + Style.RESET_ALL)


    if d_debug:
        print(Fore.RED + result.stderr + Style.RESET_ALL)
        print(Fore.GREEN + result.stdout + Style.RESET_ALL)

    if dap_file.__contains__("basicTypeDefine.dap"):
        if (result.returncode != 0):
            print(Fore.RED, "FAIL:" + Fore.BLUE + " <basic type definition>\n" + Style.RESET_ALL)
            print(Fore.YELLOW + "stderr:" + Style.RESET_ALL)
            print(Fore.YELLOW + result.stderr + Style.RESET_ALL)
            add_failed_test(dap_file)
        if (result.stderr.__contains__("error") or result.stderr.__contains__("warning") or result.stderr.__contains__("Error")) \
            or (result.stdout.__contains__("error") or result.stdout.__contains__("warning") or result.stdout.__contains__("Error")):
            print(Fore.RED, "FAIL:" + Fore.BLUE + " <basic type definition>\n" + Style.RESET_ALL)
            print(Fore.YELLOW + "stderr:" + Style.RESET_ALL)
            print(Fore.YELLOW + result.stderr + Style.RESET_ALL)
            add_failed_test(dap_file)
        else:
            success()
            print(Fore.GREEN + "PASS!" + Style.RESET_ALL)