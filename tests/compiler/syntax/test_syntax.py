import os.path
import shlex
import subprocess
from pathlib import Path

from colorama import Fore, Style

from compiler.syntax.basicTypeDefine_test import testBasicTypeDefine
from compiler.syntax.forControlFlow_test import testForControlFlow
from compiler.syntax.ifControlFlow_test import testIfControlFlow
from compiler.syntax.structTypeDefine_test import testStructTypeDefine
from compiler.syntax.returnStmt_test import testReturnStmt
from compiler.syntax.functionCallStmt_test import testFunctionCallStmt
from compiler.syntax.functionDeclaration_test import testFunctionDeclaration
from compiler.syntax.binaryExpressoin_test import testBinaryExpression


def test_syntax(dap_main, source_runtime_dir, debug_mode = False):
    """
    Test the syntax of the code.
    """

    testBasicTypeDefine(dap_main, source_runtime_dir, debug_mode)
    testStructTypeDefine(dap_main, source_runtime_dir, debug_mode)
    testReturnStmt(dap_main, source_runtime_dir, debug_mode)
    testFunctionCallStmt(dap_main, source_runtime_dir, debug_mode)
    testFunctionDeclaration(dap_main, source_runtime_dir, debug_mode)
    testBinaryExpression(dap_main, source_runtime_dir, debug_mode)
    testForControlFlow(dap_main, source_runtime_dir, debug_mode)
    testIfControlFlow(dap_main, source_runtime_dir, debug_mode)