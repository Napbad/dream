import os
from pathlib import Path

from colorama import Fore, Style

from compiler import config
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

def test_report_default(result, dap_file, test_name):
    if (result.stderr.__contains__("error") or result.stderr.__contains__("warning") or result.stderr.__contains__("Error")) \
        or (result.stdout.__contains__("error") or result.stdout.__contains__("warning") or result.stdout.__contains__("Error")):
        print(Fore.RED, "FAIL:" + Fore.BLUE + " <" + test_name + ">\n" + Style.RESET_ALL)
        print(Fore.YELLOW + "stderr:" + Style.RESET_ALL)
        print(Fore.YELLOW + result.stderr + Style.RESET_ALL)
        add_failed_test(dap_file.__str__())
    else:
        success()
        print(Fore.GREEN + "" + test_name + " test PASS!" + Style.RESET_ALL)


def build_executable_file_command(dap_main, dap_file):
    arg = ""
    project_path = config.config.get("dap", {}).get("project-path")
    dap_build_executable_directory = config.config.get("dap", {}).get("test", {}).get("dap-build-executable-directory")
    dap_build_executable_name = config.config.get("dap", {}).get("test", {}).get("dap-build-executable-name")

    build_directory = project_path + dap_build_executable_directory
    source_runtime_dir = project_path + config.config.get("dap", {}).get("test", {}).get("dap-source-runtime-dir")

    command_list = [
        Path(os.path.abspath(dap_main)).__str__(),
        os.path.abspath(dap_file),
        "-o",
        build_directory,
        "-n",
        dap_build_executable_name,
        "-s",
        source_runtime_dir
    ]

    return command_list


def run_executable_target():
    project_path = config.config.get("dap", {}).get("project-path")
    dap_build_executable_directory = config.config.get("dap", {}).get("test", {}).get("dap-build-executable-directory")
    dap_build_executable_name = config.config.get("dap", {}).get("test", {}).get("dap-build-executable-name")

    target = project_path + dap_build_executable_directory + dap_build_executable_name

    command_list = [
        target
    ]
    return command_list

def test_report_compare(result, dap_file, test_name, expect_contain_word):

    if result.returncode != 0:
        print(Fore.RED + "Error: " + Style.RESET_ALL + result.stderr)
        print(Fore.RED + "Error: " + Style.RESET_ALL + result.stdout)
        add_failed_test(dap_file)
        return

    b1 = result.stderr.__contains__("error")
    b2 = result.stderr.__contains__("warning")
    b3 = result.stderr.__contains__("Error")
    b4 = result.stdout.__contains__("error")
    b5 = result.stdout.__contains__("warning")
    b6 = result.stdout.__contains__("Error")

    if (result.stderr.__contains__("error") or result.stderr.__contains__("warning") or result.stderr.__contains__("Error")) \
        or (result.stdout.__contains__("error") or result.stdout.__contains__("warning") or result.stdout.__contains__("Error")):
        print(Fore.RED, "FAIL:" + Fore.BLUE + " <" + test_name + ">\n" + Style.RESET_ALL)
        print(Fore.YELLOW + "stderr:" + Style.RESET_ALL)
        print(Fore.YELLOW + result.stderr + Style.RESET_ALL)
        add_failed_test(dap_file.__str__())
        return 
    if result.stdout.__contains__(expect_contain_word):
        success()
        print(Fore.GREEN + "" + test_name + " test PASS!" + Style.RESET_ALL)
    else:
        add_failed_test(dap_file)

        
def report_failed_test(dap_file):
    if isinstance(dap_file, str):
        add_failed_test(dap_file)
        return
    add_failed_test(str(dap_file))