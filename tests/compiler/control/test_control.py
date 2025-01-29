import os.path
import shlex
import subprocess
from pathlib import Path

from colorama import Fore, Style

from test_res import success
from compiler.control.for_test import testBasicForControlFlow
from compiler.control.if_test import testBasicIfControlFlow
from util import get_dap_files


def testControlFlow(dap_main, source_runtime_dir, debug_mode = False):
    testBasicIfControlFlow(dap_main, source_runtime_dir, debug_mode)
    testBasicForControlFlow(dap_main, source_runtime_dir, debug_mode)
