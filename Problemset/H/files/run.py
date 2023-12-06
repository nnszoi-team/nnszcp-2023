from os import *
from random import *

system("rm data/*")
system("mkdir ./data")

var = []
ano = []
scr = []


def generate(n, t, sc, subtask, count, title, num):
    system(
        f"./gen --n={n} --t={t} > ./data/{f'{count:03d}'}_{f'{subtask:03d}'}_{title}_{f'{num:03d}'}.in"
    )
    var.append(f"{f'{count:03d}'}_{f'{subtask:03d}'}_{title}_{f'{num:03d}'}")
    ano.append(subtask)
    scr.append(sc)


system("g++ ./files/generator.cpp -o ./gen -Ofast")

for i in range(1, 5):
    generate(6 + i, 0, 13, 0, i, "small", i)

for i in range(5, 13):
    generate(1000 - i + 5, randint(-100, 100), 21, 1, i, "square_rand", i - 4)

for i in range(13, 19):
    generate(100000 - i + 13, 210000000, 12, 2, i, "spec_chain", i - 12)

for i in range(19, 26):
    generate(100000 - i + 19, -210000000, 12, 3, i, "spec_star", i - 18)

for i in range(26, 41):
    generate(100000 - i + 26, randint(-100, 100), 42, 4, i, "big_rand", i - 25)

for i in range(41, 46):
    generate(100000 - i + 41, -10000, 42, 4, i, "big_star_like", i - 40)

for i in range(46, 51):
    generate(100000 - i + 46, 10000, 42, 4, i, "big_chain_like", i - 45)

system("g++ ./files/validator.cpp -o ./val -O2")

for i in range(1, 51):
    system(f"./val < ./data/{var[i - 1]}.in > ./data/{var[i - 1]}.ans")

solname = "escapist_solution"

system("ulimit -s 65536")

system(f"g++ ./solution/{solname}.cpp -o ./{solname} -O2 -static")

for i in range(1, 51):
    system(f"./{solname} < ./data/{var[i - 1]}.in > ./data/{var[i - 1]}.ans")


def write(content):
    system(f'echo "{content}" >> {filename}')


filename = "./data/config.yml"

for i in range(1, 51):
    write(f"{var[i - 1]}.in:")
    write("    timeLimit: 2000")
    write("    memoryLimit: 262144")
    write(f"    score: {scr[i - 1]}")
    write(f"    subtaskId: {ano[i - 1]}")
    write("")

system("rm ./gen")
system("rm ./val")
system(f"rm ./{solname}")
system("cd data")
system("ls")
