import os

while True:
    print("----------------------------------------------------------------")
    os.system("python3 ./files/rand_ws.py > data.in")
    os.system("python ./solution/py_solution.py < data.in > data.out")
    if os.system("./files/checker.exe data.in data.out data.out") != False:
        break
