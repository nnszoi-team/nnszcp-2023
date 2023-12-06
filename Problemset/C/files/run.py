from os import *
from random import *

system("rm data/*")
system("mkdir ./data")

var = []
ano = []
scr = []

def generate(n, m, sc, subtask, count, title, num):
    system(f"./gen --n={n} --m={m} > ./data/{f'{count:02d}'}_{subtask}_{title}_{f'{num:02d}'}.in")
    var.append(f"{f'{count:02d}'}_{subtask}_{title}_{f'{num:02d}'}")
    ano.append(subtask)
    scr.append(sc)

def generate_equal(sc, subtask, count, title, num):
    system(f"python3 ./files/equal.py > ./data/{f'{count:02d}'}_{subtask}_{title}_{f'{num:02d}'}.in")
    var.append(f"{f'{count:02d}'}_{subtask}_{title}_{f'{num:02d}'}")
    ano.append(subtask)
    scr.append(sc)

def write(content):
    system(f"echo \"{content}\" >> {filename}")

solname = "solution.cpp"

def compile():
    system("g++ ./files/generator.cpp -o ./gen -Ofast")
    system("g++ ./files/validator.cpp -o ./val -O2")
    system(f"g++ ./solution/{solname} -o ./sol -O2 -static")

compile()

for i in range(1, 3):
    generate(randint(50, 100), randint(50, 100), 20, 0, i, "small", i)

for i in range(3, 5):
    generate_equal(10, 1, i, "spec", i - 2)

for i in range(5, 9):
    generate(randint(1900, 2000), randint(99900, 100000), 70, 2, i, "small", i - 4)

system("ulimit -s 65536")

for i in range(1, 9):
    system(f"./sol < ./data/{var[i - 1]}.in > ./data/{var[i - 1]}.ans")

filename = "./data/config.yml"

for i in range(1, 9):
    write(f"{var[i - 1]}.in:")
    write("    timeLimit: 1000")
    write("    memoryLimit: 131072")
    write(f"    score: {scr[i - 1]}")
    write(f"    subtaskId: {ano[i - 1]}")
    write('')

system("rm ./gen")
system("rm ./val")
system(f"rm ./sol")
system("cd data")
system("ls")

