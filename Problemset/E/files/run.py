from os import *
from random import *

filesFloderName = "./files"
dataFloderName = "./testdata"
solutionName = "./solution/empty.py"
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
    gen("subtask0.py", 0, i, "n_equal_to_one", 10)
for i in range(3, 7):
    gen("subtask1.py", 1, i, "n_less_than_five", 15)
for i in range(7, 16):
    gen("subtask2.py", 2, i, "n_less_than_one_hundred", 25)
for i in range(16, 26):
    gen("subtask3.py", 3, i, "n_less_than_five_hundred", 50)

for test in testList:
    print(f"{test[0]}.in:")
    print(f"    timeLimit: 1000")
    print(f"    memoryLimit: 131072")
    print(f"    score: {test[1]}")
    print(f"    subtaskId: {test[2]}")
    print()
