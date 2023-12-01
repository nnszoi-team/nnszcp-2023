from os import *
from random import *

filesFloderName = "files"
dataFloderName = "testdata"
solutionName = ".\\solution\\solution.exe"
testList = []


def gen(generatorName, subtaskId, testId, subtaskStr, score):
    filename = f"{f'{testId:03d}'}_{f'{subtaskId:03d}'}_{subtaskStr}"
    system(
        f"python {filesFloderName}\\{generatorName} > {dataFloderName}\\{filename}.in"
    )
    system(
        f"{solutionName} < {dataFloderName}\\{filename}.in > {dataFloderName}\\{filename}.ans"
    )
    testList.append([filename, score, subtaskId])
    pass


for i in range(1, 2):
    gen("empty.py", 0, i, "empty", 2)

for i in range(2, 6):
    gen("small_ws.py", 1, i, "small", 23)

for i in range(6, 14):
    gen("gauss_ws.py", 2, i, "gauss", 27)

for i in range(14, 22):
    gen("without_optimize_ws.py", 3, i, "without_optimize", 20)

for i in range(22, 31):
    gen("rand_ws.py", 4, i, "rand", 28)

for test in testList:
    print(f"{test[0]}.in:")
    print(f"    timeLimit: 2000")
    print(f"    memoryLimit: 262144")
    print(f"    score: {test[1]}")
    print(f"    subtaskId: {test[2]}")
    print()
