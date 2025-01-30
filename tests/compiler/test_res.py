import threading


testNum = 0
passedTest = 0
failedTest = 0
lock = threading.Lock()
failedTestList = []

# def add_failed_test(test_name):
#     global failedTest
#     failedTest += 1
#     global failedTestList
#     failedTestList.append(test_name)

# def success():
#     global passedTest
#     print("Test passed")
#     passedTest += 1
#     print(passedTest)

# def add_failed_test(test_name):
#     global failedTest
#     failedTest += 1
#     global failedTestList
#     failedTestList.append(test_name)
#     print(f"Test {test_name} failed. Current passedTest: {passedTest}, failedTest: {failedTest}")

# def success():
#     global passedTest
#     print("Test passed")
#     passedTest += 1
#     print(passedTest)
#     print(f"Test passed. Current passedTest: {passedTest}, failedTest: {failedTest}")


def add_failed_test(test_name):
    global failedTest
    global failedTestList
    with lock:
        failedTest += 1
        failedTestList.append(str(test_name))

def success():
    global passedTest
    with lock:
        print("Test passed")
        passedTest += 1
        print(passedTest)


def print_result():
    global testNum
    global passedTest
    global failedTest
    global failedTestList
    print("Tested %d tests, %d passed, %d failed" % (passedTest + failedTest, passedTest, failedTest))
    if failedTest > 0:
        print("Failed tests:")
        for test in failedTestList:
            print("\n\t" + test)