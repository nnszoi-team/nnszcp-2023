from os import *
from random import *

filesFloderName = "files"
dataFloderName = "testdata"
solutionName = "./solution/py_solution.py"
testList = []


def gen(generatorName, subtaskId, testId, subtaskStr, score, info):
    filename = f"{f'{testId:03d}'}_{f'{subtaskId:03d}'}_{subtaskStr}"
    system(
        f"python3 ./{filesFloderName}/{generatorName} {info} > ./{dataFloderName}/{filename}.in"
    )
    system(
        f"python3 {solutionName} < ./{dataFloderName}/{filename}.in > ./{dataFloderName}/{filename}.ans"
    )
    testList.append([filename, score, subtaskId])
    pass

def divide(n):
    l, r = randint(1, n), randint(1, n)
    if l > r:
        l, r = r, l
    return f"{l} {r - l} {n - r}"


for i in range(1, 2):
    n = randint(8, 10)
    q = randint(8, 10)
    gen("rws.py", 1, i, "small", 23, f"{n} {q} {n} {divide(n)}")

for i in range(2, 8):
    gen("rws.py", 1, i, "small", 23)

for i in range(8, 19):
    gen("rws.py", 2, i, "gauss", 27)

for i in range(19, 30):
    gen("rws.py", 3, i, "middle", 20)

for i in range(30, 36):
    gen("rws.py", 4, i, "rand", 28)

for test in testList:
    print(f"{test[0]}.in:")
    print(f"    timeLimit: 2000")
    print(f"    memoryLimit: 524288")
    print(f"    score: {test[1]}")
    print(f"    subtaskId: {test[2]}")
    print()
