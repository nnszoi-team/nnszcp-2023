from os import *
from random import *

system("rm data/*")
system("mkdir ./data")

var = []
ano = []
scr = []

def generate(n, q, p, t, only, sc, subtask, count, title, num):
    print(f"generator run on {count}")
    system(f"./gen --n={n} --q={q} --p={p} --t={t} --only={only} > ./data/{f'{count:02d}'}_{subtask}_{title}_{f'{num:02d}'}.in")
    var.append(f"{f'{count:02d}'}_{subtask}_{title}_{f'{num:02d}'}")
    ano.append(subtask)
    scr.append(sc)

system("g++ ./files/generator.cpp -o ./gen -Ofast")

count = 1

for i in range(1, 2):
    generate(20000, 0, 0, 0, 0, 2, 0, count, "no_query", i)
    count += 1

for i in range(1, 5):
    generate(10 - i + 1, 10 - i + 1, 5, 10 - i + 1, 0, 13, 1, count, "brute_force", i)
    count += 1

for i in range(1, 6):
    generate(100 - i + 1, 100 - i + 1, 0, 50 - i + 1, 0, 17, 2, count, "only_two", i)
    count += 1

for i in range(1, 11):
    generate(1000 - i + 1, 1000 - i + 1, randint(3, 10), randint(2, 50 - i + 1), 1, 27, 3, count, "except_two", i)
    count += 1

for i in range(1, 16):
    generate(20000 - i + 1, 20000 - i + 1, randint(5000, 10000), randint(2, 20000 - i + 1), 0, 41, 4, count, "big", i)
    count += 1

for i in range(1, 3):
    generate(20000 - i + 1, 20000 - i + 1, 10, 1 + i, 0, 41, 4, count, "small_range", i)
    count += 1

for i in range(1, 3):
    generate(20000 - i + 1, 20000 - i + 1, 10, 19000, 0, 41, 4, count, "big_range", i)
    count += 1

for i in range(1, 3):
    generate(20000 - i + 1, 20000 - i + 1, 5, 150, 0, 41, 4, count, "square_root_range", i)
    count += 1

system("g++ ./files/validator.cpp -o ./val -O2")

print(count)

for i in range(1, count):
    system(f"./val < ./data/{var[i - 1]}.in > ./data/{var[i - 1]}.ans")

solname = "esc_solution"

system("ulimit -s 65536")

system(f"g++ ./solution/{solname}.cpp -o ./{solname} -O2 -static")

for i in range(1, count):
    print(f"valicator run on {i}")
    system(f"./{solname} < ./data/{var[i - 1]}.in > ./data/{var[i - 1]}.ans")

def write(content):
    system(f"echo \"{content}\" >> {filename}")

filename = "./data/config.yml"

for i in range(1, count):
    write(f"{var[i - 1]}.in:")
    write("    timeLimit: 2000")
    write("    memoryLimit: 262144")
    write(f"    score: {scr[i - 1]}")
    write(f"    subtaskId: {ano[i - 1]}")
    write('')
    
system("rm ./gen")
system("rm ./val")
system(f"rm ./{solname}")
system("cd data")
system("ls")

