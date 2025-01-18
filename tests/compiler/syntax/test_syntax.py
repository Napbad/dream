import os.path
import subprocess
from pathlib import Path

from colorama import Fore, Style

from test_res import success, add_failed_test
from syntax.basicTypeDefine_test import testBasicTypeDefine
from syntax.structTypeDefine_test import testStructTypeDefine
from syntax.returnStmt_test import testReturnStmt
from syntax.functionCallStmt_test import testFunctionCallStmt
from syntax.functionDeclaration_test import testFunctionDeclaration
from util import get_dap_files


def test_syntax(dap_main, source_runtime_dir, d_debug = False):
    """
    Test the syntax of the code.
    """

    testBasicTypeDefine(dap_main, source_runtime_dir, d_debug)
    testStructTypeDefine(dap_main, source_runtime_dir, d_debug)
    testReturnStmt(dap_main, source_runtime_dir, d_debug)
    testFunctionCallStmt(dap_main, source_runtime_dir, d_debug)
    testFunctionDeclaration(dap_main, source_runtime_dir, d_debug)