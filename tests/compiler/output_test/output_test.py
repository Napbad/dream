import os.path
import shlex
import subprocess
from pathlib import Path

from colorama import Fore, Style

from test_res import success, add_failed_test
from output_test.help_test import test_help
from output_test.version_test import test_version
from util import get_dap_files

def test_output(dap_main, source_runtime_dir, D_DEBUG = False, debug_mode = False):
    test_help(dap_main, source_runtime_dir, D_DEBUG, debug_mode)
    test_version(dap_main, source_runtime_dir, D_DEBUG, debug_mode)