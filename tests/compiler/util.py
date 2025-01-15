import os

from colorama import Fore, Style

from test_res import add_failed_test, success


def get_dap_files(directory):
    dap_files = []
    for root, dirs, files in os.walk(directory):
        for file in files:
            if file.endswith('.dap'):
                dap_files.append(os.path.join(root, file))
    return dap_files

# Example usage:
# directory_path = "/your/specified/directory"
# result = get_dap_files(directory_path)
# print(result)

def check_output(command, expect):

    return True


def test_single_file(dap_main, source_runtime_dir, dap_file):
    
    return 

def test_report_default(result, dap_file):
    if (result.stderr.__contains__("error") or result.stderr.__contains__("warning") or result.stderr.__contains__("Error")) \
        or (result.stdout.__contains__("error") or result.stdout.__contains__("warning") or result.stdout.__contains__("Error")):
        print(Fore.RED, "FAIL:" + Fore.BLUE + " <struct type definition>\n" + Style.RESET_ALL)
        print(Fore.YELLOW + "stderr:" + Style.RESET_ALL)
        print(Fore.YELLOW + result.stderr + Style.RESET_ALL)
        add_failed_test(dap_file)
    else:
        success()
        print(Fore.GREEN + "struct type definition test PASS!" + Style.RESET_ALL)