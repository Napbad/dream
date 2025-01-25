

import os
import shlex
import subprocess
from colorama import Fore, Style

from compiler.test_res import success, add_failed_test


def test_version(dap_main, source_runtime_dir, D_DEBUG = False, debug_mode = False):
    print(Fore.BLUE + "Testing version output" + Style.RESET_ALL)
    result = subprocess.run(dap_main + " -v",  capture_output=True, text=True, shell=True)
    if result.returncode == 0:

        if debug_mode:
            if result.stdout.__contains__("dap version: "):

                print(Fore.GREEN + "version output PASSED!" + Style.RESET_ALL)
                success()
            else:
                print(Fore.RED + "version output FAILED" + Style.RESET_ALL)   
                print(Fore.RED + result.stderr + Style.RESET_ALL)
                print(Fore.RED + result.stdout + Style.RESET_ALL)
                add_failed_test(Fore.BLUE + "<version output> " + Fore.RED + "[failed] " +  Fore.CYAN + " path: " + os.path.abspath(__file__))

    else:
        print(Fore.RED + "version output FAILED" + Style.RESET_ALL)
        print(Fore.RED + result.stderr + Style.RESET_ALL)
        print(Fore.RED + result.stdout + Style.RESET_ALL)
        