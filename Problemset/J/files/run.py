from os import *
from random import *

filesFloderName = "./files"
dataFloderName = "./data"
solutionName = "./solution/solution"
testList = []

def gen(generatorName, subtaskId, testId, subtaskStr, score):
    filename = f"{f'{testId:03d}'}_{f'{subtaskId:03d}'}_{subtaskStr}"
    system(f"python3 {filesFloderName}/{generatorName} > {dataFloderName}/{filename}.in")
    system(f"{solutionName} < {dataFloderName}/{filename}.in > {dataFloderName}/{filename}.ans")
    testList.append([filename, score, subtaskId])
    pass

for i in range(1, 3):
    gen("subtask0.py", 0, i, "p_max_random", 10)
for i in range(3, 9):
    gen("subtask1-1.py", 1, i, "p_t_prime", 13)
for i in range(9, 14):
    gen("subtask1-2.py", 1, i, "p_t_random", 13)
for i in range(14, 19):
    gen("subtask2-1.py", 2, i, "p_half_t_prime", 21)
for i in range(19, 25):
    gen("subtask2-2.py", 2, i, "p_half_t_random", 21)
for i in range(25, 32):
    gen("subtask3-1.py", 3, i, "p_sqrt_t_prime", 25)
for i in range(32, 40):
    gen("subtask3-2.py", 3, i, "p_sqrt_t_random", 25)
for i in range(40, 45):
    gen("subtask4-1.py", 4, i, "p_two_random", 31)
for i in range(45, 54):
    gen("subtask4-2.py", 4, i, "p_two_prime", 31)
for i in range(54, 58):
    gen("subtask4-3.py", 4, i, "p_two_pow", 31)
for i in range(58, 61):
    gen("subtask4-4.py", 4, i, "p_two_big", 31)

for test in testList:
    print(f"{test[0]}.in:")
    print(f"    timeLimit: 2000")
    print(f"    memoryLimit: 262144")
    print(f"    score: {test[1]}")
    print(f"    subtaskId: {test[2]}")
    print()
