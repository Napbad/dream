import os


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