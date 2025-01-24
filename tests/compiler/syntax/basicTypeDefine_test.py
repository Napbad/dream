import os.path
import subprocess
from pathlib import Path

from colorama import Fore, Style

from test_res import success, add_failed_test
from util import get_dap_files, test_report_default


def testBasicTypeDefine(dap_main, source_runtime_dir, d_debug = False):
    arg = ""

    script_path = Path(__file__).resolve()
    script_dir = script_path.parent
    dap_file = script_dir / "basicTypeDefine_test.dap"
    # Correct the command list by removing the extra spaces around -s
    command_list = [
        Path(os.path.abspath(dap_main)).__str__(),
        os.path.abspath(dap_file),
        arg.strip()  # Also remove any extra spaces from the arg if present
    ]
    result = subprocess.run(command_list, capture_output=True, text=True)

    print(Fore.BLUE + f"Testing: {dap_file}" + Style.RESET_ALL)


    if d_debug:
        print(Fore.RED + result.stderr + Style.RESET_ALL)
        print(Fore.GREEN + result.stdout + Style.RESET_ALL)

    test_report_default(result, dap_file, "basic type definition")
