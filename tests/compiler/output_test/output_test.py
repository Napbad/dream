import os.path
import shlex
import subprocess
from pathlib import Path

from colorama import Fore, Style

from compiler.output_test.help_test import test_help
from compiler.output_test.version_test import test_version


def test_output(dap_main, source_runtime_dir, D_DEBUG = False, debug_mode = False):
    test_help(dap_main, source_runtime_dir, D_DEBUG, debug_mode)
    test_version(dap_main, source_runtime_dir, D_DEBUG, debug_mode)