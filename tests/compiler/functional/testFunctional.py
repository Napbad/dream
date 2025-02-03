from compiler.functional.funCall_test import testFunCall
from compiler.functional.funReturn_test import testFunReturn


def testFunctional(dap_main, source_runtime_dir, debug_mode = False):
    testFunCall(dap_main, source_runtime_dir, debug_mode)
    testFunReturn(dap_main, source_runtime_dir, debug_mode)