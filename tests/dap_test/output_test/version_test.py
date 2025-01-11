

import os
import subprocess
from colorama import Fore, Style

from test_res import add_failed_test, success


def test_version(dap_main, source_runtime_dir, D_DEBUG = False):
    print(Fore.BLUE + "Testing version output" + Style.RESET_ALL)
    result = subprocess.run([dap_main, "-v"],  capture_output=True, text=True)
    if result.returncode == 0:

        if D_DEBUG:
            if result.stdout.__contains__("dap version: "):

                print(Fore.GREEN + "version output PASSED!" + Style.RESET_ALL)
                success()
            else:
                print(Fore.RED + "version output FAILED" + Style.RESET_ALL)   
                print(Fore.RED + result.stderr + Style.RESET_ALL)
                print(Fore.RED + result.stdout + Style.RESET_ALL)
                add_failed_test(Fore.BLUE + "<version output> " + Fore.RED + "[failed] " +  Fore.CYAN + " path: " + os.path.abspath(__file__))
        else:
            if result.stdout.__contains__("dap version: ") :

                print(Fore.GREEN + "version output PASSED!" + Style.RESET_ALL)
            
            else:
                print(Fore.RED + "version output FAILED" + Style.RESET_ALL)   
                print(Fore.RED + result.stderr + Style.RESET_ALL)
                print(Fore.RED + result.stdout + Style.RESET_ALL)
    else:
        print(Fore.RED + "version output FAILED" + Style.RESET_ALL)
        print(Fore.RED + result.stderr + Style.RESET_ALL)
        print(Fore.RED + result.stdout + Style.RESET_ALL)
        