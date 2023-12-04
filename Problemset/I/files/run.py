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

def divide(n, zero_percent, two_percent):
    z = int(n * zero_percent)
    t = int((n - z) * two_percent)
    o = n - z - t
    return f"{z} {o}"

gen("rws.py", 0, 1, "empty", 2, f"{300000} {0} {1} {300000} {divide(500000, 0.0, 0.0)}")

for i in range(2, 6):
    n = randint(8, 10)
    q = randint(8, 10)
    gen("rws.py", 1, i, "small", 23, f"{n} {q} {1} {randint(5, n)} {divide(n, uniform(0, 0.2), uniform(0.7, 0.8))}")

for i in range(6, 7):
    n = randint(8, 10)
    q = randint(8, 10)
    gen("dws.py", 1, i, "small", 23, f"{n} {q} {1} {randint(5, n)} {divide(n, uniform(0, 0.2), uniform(0.7, 0.8))}")

for i in range(7, 10):
    n = randint(1990, 2000)
    q = randint(1990, 2000)
    gen("rws.py", 2, i, "gauss", 27, f"{n} {q} {1} {randint(4, n // 3)} {divide(n, uniform(0, 0.002), uniform(0.7, 0.8))}")

for i in range(10, 11):
    n = randint(1990, 2000)
    q = randint(1990, 2000)
    gen("dws.py", 2, i, "gauss", 27, f"{n} {q} {1} {randint(4, n // 3)} {divide(n, uniform(0, 0.002), uniform(0.7, 0.8))}")

for i in range(11, 13):
    n = randint(1990, 2000)
    q = randint(1990, 2000)
    gen("rws.py", 2, i, "gauss", 27, f"{n} {q} {1} {randint(2, 4)} {divide(n, uniform(0, 0.001), uniform(0.7, 0.8))}")

for i in range(13, 15):
    n = randint(1990, 2000)
    q = randint(1990, 2000)
    gen("dws.py", 2, i, "gauss", 27, f"{n} {q} {1} {randint(2, 4)} {divide(n, uniform(0, 0.001), uniform(0.7, 0.8))}")

for i in range(15, 17):
    n = randint(1990, 2000)
    q = randint(1990, 2000)
    gen("rws.py", 2, i, "gauss", 27, f"{n} {q} {1} {n} {divide(n, 0, 0.5)}")

for i in range(17, 19):
    n = randint(1990, 2000)
    q = randint(1990, 2000)
    gen("rws.py", 2, i, "gauss", 27, f"{n} {q} {n - 3} {n} {divide(n, 0, 0.5)}")

for i in range(19, 21):
    n = randint(1990, 2000)
    q = randint(1990, 2000)
    gen("dws.py", 2, i, "gauss", 27, f"{n} {q} {1} {n} {divide(n, 0, 0.5)}")

for i in range(21, 23):
    n = randint(1990, 2000)
    q = randint(1990, 2000)
    gen("dws.py", 2, i, "gauss", 27, f"{n} {q} {n - 5} {n} {divide(n, 0, 0.5)}")

for i in range(23, 26):
    n = randint(299995, 300000)
    q = randint(299995, 300000)
    gen("rws.py", 3, i, "single", 16, f"{n} {q} {1} {1} {divide(n, 0.333, 0.5)}")

for i in range(26, 30):
    n = randint(299995, 300000)
    q = randint(299995, 300000)
    gen("dws.py", 3, i, "single", 16, f"{n} {q} {1} {1} {divide(n, uniform(0.00001, 0.002), uniform(0.9, 0.95))}")

for i in range(30, 33):
    n = randint(299990, 300000)
    q = randint(299990, 300000)
    gen("rws.py", 4, i, "big", 32, f"{n} {q} {1} {randint(500, n)} {divide(n, uniform(0.00001, 0.004), uniform(0.9, 0.95))}")

for i in range(33, 35):
    n = randint(299990, 300000)
    q = randint(299990, 300000)
    gen("dws.py", 4, i, "big", 32, f"{n} {q} {1} {randint(500, n)} {divide(n, uniform(0.00001, 0.004), uniform(0.9, 0.95))}")

for i in range(35, 37):
    n = randint(299990, 300000)
    q = randint(299990, 300000)
    gen("rws.py", 4, i, "big", 32, f"{n} {q} {1} {randint(3, 10)} {divide(n, uniform(0.00001, 0.002), uniform(0.9, 0.95))}")

for i in range(37, 39):
    n = randint(299990, 300000)
    q = randint(299990, 300000)
    gen("dws.py", 4, i, "big", 32, f"{n} {q} {1} {randint(3, 10)} {divide(n, uniform(0.00001, 0.002), uniform(0.9, 0.95))}")

for i in range(39, 41):
    n = randint(299990, 300000)
    q = randint(299990, 300000)
    gen("rws.py", 4, i, "big", 32, f"{n} {q} {1} {n} {divide(n, 0, 0.5)}")

for i in range(41, 42):
    n = randint(299998, 300000)
    q = randint(299998, 300000)
    gen("rws.py", 4, i, "big", 32, f"{n} {q} {1} {3} {divide(n, 0.333, 0.5)}")

for i in range(42, 44):
    n = randint(299950, 300000)
    q = randint(299950, 300000)
    gen("dws.py", 4, i, "big", 32, f"{n} {q} {1} {n} {divide(n, 0, 0.5)}")

for i in range(44, 46):
    n = randint(299998, 300000)
    q = randint(299998, 300000)
    gen("dws.py", 4, i, "big", 32, f"{n} {q} {1} {3} {divide(n, 0.333, 0.5)}")


for test in testList:
    print(f"{test[0]}.in:")
    print(f"    timeLimit: 2000")
    print(f"    memoryLimit: 262144")
    print(f"    score: {test[1]}")
    print(f"    subtaskId: {test[2]}")
    print()
