from os import *
from random import *

system("rm data/*")
system("mkdir ./data")

var = []
ano = []
scr = []

def generate_0(sc, subtask, count, title, num):
    system(f"python3 ./files/small.py > ./data/{f'{count:02d}'}_{subtask}_{title}_{f'{num:02d}'}.in")
    var.append(f"{f'{count:02d}'}_{subtask}_{title}_{f'{num:02d}'}")
    ano.append(subtask)
    scr.append(sc)

def generate_1(sc, subtask, count, title, num):
    system(f"python3 ./files/spec.py > ./data/{f'{count:02d}'}_{subtask}_{title}_{f'{num:02d}'}.in")
    var.append(f"{f'{count:02d}'}_{subtask}_{title}_{f'{num:02d}'}")
    ano.append(subtask)
    scr.append(sc)

def generate_2(sc, subtask, count, title, num):
    system(f"python3 ./files/random_gen.py > ./data/{f'{count:02d}'}_{subtask}_{title}_{f'{num:02d}'}.in")
    var.append(f"{f'{count:02d}'}_{subtask}_{title}_{f'{num:02d}'}")
    ano.append(subtask)
    scr.append(sc)

def write(content):
    system(f"echo \"{content}\" >> {filename}")

solname = "solution.cpp"

def compile():
    # system("g++ ./files/generator.cpp -o ./gen -Ofast")
    system("g++ ./files/validator.cpp -o ./val -O2")
    system(f"g++ ./solution/{solname} -o ./sol -O2 -static")

compile()

# generate_0(20, 0, 1, "spec_b", 1)

# generate_1(30, 1, 2, "random", 1)

for i in range(1, 5):
    generate_0(20, 0, i, "small", i)

for i in range(5, 9):
    generate_1(30, 1, i, "spec", i - 4)

for i in range(9, 17):
    generate_2(50, 2, i, "random", i - 7)

system("ulimit -s 65536")

for i in range(1, 17):
    system(f"./sol < ./data/{var[i - 1]}.in > ./data/{var[i - 1]}.ans")

# for i in range(1, 5):
#     system(f"./val --distinct=0 < ./data/{var[i - 1]}.in")

# for i in range(5, 9):
#     print(i)
#     system(f"./val --distinct=1 < ./data/{var[i - 1]}.in")

# for i in range(9, 17):
#     system(f"./val --distinct=0 < ./data/{var[i - 1]}.in")

filename = "./data/config.yml"

for i in range(1, 17):
    write(f"{var[i - 1]}.in:")
    write("    timeLimit: 2000")
    write("    memoryLimit: 262144")
    write(f"    score: {scr[i - 1]}")
    write(f"    subtaskId: {ano[i - 1]}")
    write('')

system("rm ./gen")
system("rm ./val")
system(f"rm ./sol")
system("cd data")
system("ls")

