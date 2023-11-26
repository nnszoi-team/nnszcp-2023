from os import *
from random import *

filesFloderName = "./files"
dataFloderName = "./data"
solutionName = "./solution/solution"
testList = []

def gen(subtaskId, testId, score):
    filename = f"{f'{testId:03d}'}_{f'{subtaskId:03d}'}"
    system(f"python3 {filesFloderName}/subtask{subtaskId}.py > {dataFloderName}/{filename}.in")
    system(f"{solutionName} < {dataFloderName}/{filename}.in > {dataFloderName}/{filename}.ans")
    testList.append([filename, score, subtaskId])
    pass

for i in range(1, 4):
    gen(0, i, 5)
for i in range(4, 9):
    gen(1, i, 12)
for i in range(9, 14):
    gen(2, i, 13)
for i in range(14, 20):
    gen(3, i, 22)
for i in range(20, 30):
    gen(4, i, 23)
for i in range(30, 46):
    gen(5, i, 25)

for test in testList:
    print(f"{test[0]}.in:")
    print(f"    timeLimit: 2000")
    print(f"    memoryLimit: 262144")
    print(f"    score: {test[1]}")
    print(f"    subtaskId: {test[2]}")
    print()
