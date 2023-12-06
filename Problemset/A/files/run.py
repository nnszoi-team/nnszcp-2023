from os import *
from random import *

system("rm data/*")
system("mkdir ./data")

var = []
ano = []
scr = []

def gen_le3(subtask, score, count, title):
    system(f"python3 ./generator_less_than_three.py > ./data/{count}_{subtask}_{title}.in")
    var.append(f"{count}_{subtask}_{title}")
    scr.append(score)
    ano.append(subtask)

def gen_eq4_no(subtask, score, count, title):
    system(f"python3 ./generator_eq_four.py > ./data/{count}_{subtask}_{title}.in")
    var.append(f"{count}_{subtask}_{title}")
    scr.append(score)
    ano.append(subtask)

def gen_eq4_yes(subtask, score, count, title):
    system(f"python3 ./generator_nnsz.py > ./data/{count}_{subtask}_{title}.in")
    var.append(f"{count}_{subtask}_{title}")
    scr.append(score)
    ano.append(subtask)

def gen_no(subtask, score, count, title):
    system(f"python3 ./generator_no.py > ./data/{count}_{subtask}_{title}.in")
    var.append(f"{count}_{subtask}_{title}")
    scr.append(score)
    ano.append(subtask)

def gen_yes(subtask, score, count, title):
    system(f"python3 ./generator_yes.py > ./data/{count}_{subtask}_{title}.in")
    var.append(f"{count}_{subtask}_{title}")
    scr.append(score)
    ano.append(subtask)

for i in range(1, 4):
    gen_le3(0, 45, i, "less_than_three")

gen_eq4_no(1, 5, 4, "equal_four")
gen_eq4_yes(1, 5, 5, "equal_four")

for i in range(6, 11):
    if i % 2 == 0:
        gen_no(2, 50, i, "random")
    else:
        gen_yes(2, 50, i, "random")

solname = "std"
system(f"g++ ./{solname}.cpp -o ./sol")

for i in range(1, 11):
    system(f"./sol < ./data/{var[i - 1]}.in > ./data/{var[i - 1]}.ans")

filename = "./data/config.yml"

def write(content):
    system(f"echo \"{content}\" >> {filename}")

for i in range(1, 11):
    write(f"{var[i - 1]}.in:")
    write("    timeLimit: 1000")
    write("    memoryLimit: 131072")
    write(f"    score: {scr[i - 1]}")
    write(f"    subtaskId: {ano[i - 1]}")
    write('')
    
system("rm ./gen")
system(f"rm ./{solname}")
system("cd data")
system("ls")

