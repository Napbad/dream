import os.path
import shlex
import subprocess
from pathlib import Path

from colorama import Fore, Style


from compiler.util import build_executable_file_command, test_report_default


def testBasicTypeDefine(dap_main, source_runtime_dir, debug_mode = False):
    arg = ""

    script_path = Path(__file__).resolve()
    script_dir = script_path.parent
    dap_file = script_dir / "basicTypeDefine_test.dap"
    # Correct the command list by removing the extra spaces around -s
    command_list = build_executable_file_command(dap_main, dap_file)
    result = subprocess.run(shlex.join(command_list), capture_output=True, text=True, shell=True)

    print(Fore.BLUE + f"Testing: {dap_file}" + Style.RESET_ALL)


    if debug_mode:
        print(Fore.RED + result.stderr + Style.RESET_ALL)
        print(Fore.GREEN + result.stdout + Style.RESET_ALL)

    test_report_default(result, dap_file, "basic type definition")
