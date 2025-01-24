testNum = 0
passedTest = 0
failedTest = 0

failedTestList = []

def add_failed_test(test_name):
    global failedTest
    failedTest += 1
    failedTestList.append(test_name)

def success():
    global passedTest
    passedTest += 1

def print_result():
    global testNum
    global passedTest
    global failedTest
    global failedTestList
    print("Tested %d tests, %d passed, %d failed" % (testNum, passedTest, failedTest))
    if failedTest > 0:
        print("Failed tests:")
        for test in failedTestList:
            print("\n\t" + test)