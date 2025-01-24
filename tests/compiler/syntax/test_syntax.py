import os.path
import subprocess
from pathlib import Path

from colorama import Fore, Style

from test_res import success, add_failed_test
from compiler.syntax.basicTypeDefine_test import testBasicTypeDefine
from compiler.syntax.structTypeDefine_test import testStructTypeDefine
from compiler.syntax.returnStmt_test import testReturnStmt
from compiler.syntax.functionCallStmt_test import testFunctionCallStmt
from compiler.syntax.functionDeclaration_test import testFunctionDeclaration
from compiler.syntax.binaryExpressoin_test import testBinaryExpression
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
    testBinaryExpression(dap_main, source_runtime_dir, d_debug)