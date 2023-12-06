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

def generate_3(sc, subtask, count, title, num):
    system(f"python3 ./files/increasing_gen.py > ./data/{f'{count:02d}'}_{subtask}_{title}_{f'{num:02d}'}.in")
    var.append(f"{f'{count:02d}'}_{subtask}_{title}_{f'{num:02d}'}")
    ano.append(subtask)
    scr.append(sc)

def generate_4(sc, subtask, count, title, num):
    system(f"python3 ./files/decreasing_gen.py > ./data/{f'{count:02d}'}_{subtask}_{title}_{f'{num:02d}'}.in")
    var.append(f"{f'{count:02d}'}_{subtask}_{title}_{f'{num:02d}'}")
    ano.append(subtask)
    scr.append(sc)

def generate_5(sc, subtask, count, title, num):
    system(f"python3 ./files/decreasing_distinct_gen.py > ./data/{f'{count:02d}'}_{subtask}_{title}_{f'{num:02d}'}.in")
    var.append(f"{f'{count:02d}'}_{subtask}_{title}_{f'{num:02d}'}")
    ano.append(subtask)
    scr.append(sc)

def generate_6(sc, subtask, count, title, num):
    system(f"python3 ./files/increasing_distinct_gen.py > ./data/{f'{count:02d}'}_{subtask}_{title}_{f'{num:02d}'}.in")
    var.append(f"{f'{count:02d}'}_{subtask}_{title}_{f'{num:02d}'}")
    ano.append(subtask)
    scr.append(sc)

def generate_7(sc, subtask, count, title, num):
    system(f"python3 ./files/increasing_distinct_small_gen.py > ./data/{f'{count:02d}'}_{subtask}_{title}_{f'{num:02d}'}.in")
    var.append(f"{f'{count:02d}'}_{subtask}_{title}_{f'{num:02d}'}")
    ano.append(subtask)
    scr.append(sc)

def generate_8(sc, subtask, count, title, num):
    system(f"python3 ./files/decreasing_distinct_small_gen.py > ./data/{f'{count:02d}'}_{subtask}_{title}_{f'{num:02d}'}.in")
    var.append(f"{f'{count:02d}'}_{subtask}_{title}_{f'{num:02d}'}")
    ano.append(subtask)
    scr.append(sc)

def generate_9(sc, subtask, count, title, num):
    system(f"python3 ./files/increasing_distinct_spec_gen.py > ./data/{f'{count:02d}'}_{subtask}_{title}_{f'{num:02d}'}.in")
    var.append(f"{f'{count:02d}'}_{subtask}_{title}_{f'{num:02d}'}")
    ano.append(subtask)
    scr.append(sc)

def generate_10(sc, subtask, count, title, num):
    system(f"python3 ./files/decreasing_distinct_spec_gen.py > ./data/{f'{count:02d}'}_{subtask}_{title}_{f'{num:02d}'}.in")
    var.append(f"{f'{count:02d}'}_{subtask}_{title}_{f'{num:02d}'}")
    ano.append(subtask)
    scr.append(sc)

def write(content):
    system(f"echo \"{content}\" >> {filename}")

solname = "bit_solution.cpp"

def compile():
    # system("g++ ./files/generator.cpp -o ./gen -Ofast")
    system("g++ ./files/validator.cpp -o ./val -O2")
    system(f"g++ ./solution/{solname} -o ./sol -O2 -static")

compile()

# generate_0(20, 0, 1, "spec_b", 1)

# generate_1(30, 1, 2, "random", 1)

for i in range(1, 3):
    generate_0(20, 0, i, "small", i)

for i in range(3, 4):
    generate_7(20, 0, i, "increasing_distinct_small", i)

for i in range(4, 5):
    generate_8(20, 0, i, "decreasing_distinct_small", i)

for i in range(5, 9):
    generate_1(30, 1, i, "spec", i - 4)

for i in range(9, 12):
    generate_9(30, 1, i, "increasing_distinct_spec", i - 4)

for i in range(12, 14):
    generate_10(30, 1, i, "decreasing_distinct_spec", i - 4)

for i in range(14, 21):
    generate_2(50, 2, i, "random", i - 13)

for i in range(21, 26):
    generate_3(50, 2, i, "increasing", i - 13)

for i in range(26, 31):
    generate_4(50, 2, i, "decreasing", i - 8)

for i in range(31, 36):
    generate_5(50, 2, i, "decreasing_distinct", i - 13)

for i in range(36, 41):
    generate_6(50, 2, i, "increasing_distinct", i - 13)

system("ulimit -s 65536")

for i in range(1, 41):
    system(f"./sol < ./data/{var[i - 1]}.in > ./data/{var[i - 1]}.ans")

for i in range(1, 5):
    system(f"./val --distinct=0 < ./data/{var[i - 1]}.in")

for i in range(5, 14):
    # print(i)
    system(f"./val --distinct=1 < ./data/{var[i - 1]}.in")

for i in range(14, 41):
    system(f"./val --distinct=0 < ./data/{var[i - 1]}.in")

filename = "./data/config.yml"

for i in range(1, 41):
    write(f"{var[i - 1]}.in:")
    write("    timeLimit: 2000")
    write("    memoryLimit: 262144")
    write(f"    score: {scr[i - 1]}")
    write(f"    subtaskId: {ano[i - 1]}")
    write('')

system("rm ./gen")
system("rm ./val")
system("rm ./sol")
system("cd data")
system("ls")
