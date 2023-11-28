from os import *
from random import *

filesFloderName = "./files"
dataFloderName = "./testdata"
solutionName = "./solution/py_solution.py"
testList = []


def gen(generatorName, subtaskId, testId, subtaskStr, score):
    filename = f"{f'{testId:03d}'}_{f'{subtaskId:03d}'}_{subtaskStr}"
    system(f"python {filesFloderName}/{generatorName} > {dataFloderName}/{filename}.in")
    system(
        f"python {solutionName} < {dataFloderName}/{filename}.in > {dataFloderName}/{filename}.ans"
    )
    testList.append([filename, score, subtaskId])
    pass


for i in range(1, 3):
    gen("small.py", 0, i, "small", 25)
for i in range(3, 7):
    gen("increasing.py", 1, i, "increasing", 25)
for i in range(7, 9):
    gen("negative_increasing.py", 1, i, "increasing", 25)
for i in range(9, 19):
    gen("rand.py", 2, i, "random", 50)
for i in range(19, 20):
    gen("other.py", 2, i, "hack", 50)
for i in range(20, 21):
    gen("negative.py", 2, i, "hack", 50)

for test in testList:
    print(f"{test[0]}.in:")
    print(f"    timeLimit: 2000")
    print(f"    memoryLimit: 262144")
    print(f"    score: {test[1]}")
    print(f"    subtaskId: {test[2]}")
    print()
