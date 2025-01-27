

import os
import shlex
import subprocess
from colorama import Fore, Style

from compiler.test_res import success, add_failed_test
from compiler.util import test_report_compare


def test_version(dap_main, source_runtime_dir, D_DEBUG = False, debug_mode = False):
    print(Fore.BLUE + "Testing version output" + Style.RESET_ALL)
    result = subprocess.run(dap_main + " -v",  capture_output=True, text=True, shell=True)

    if debug_mode:
        print(result.stdout)
        print(Fore.RED + result.stderr + Style.RESET_ALL)

    test_report_compare(result, "version", "version output test", "dap version:")