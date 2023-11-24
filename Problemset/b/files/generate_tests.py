from os import *
from random import *

system("ls")
system("g++ ./solution/esc_solution.cpp -o sol -O3")
system("g++ ./file/generator.cpp -o gen -O3")

for i in range(1, 3):
    system(f"./gen --n={10} --c={choice(range(-1, 1))} --min={-20 + i} --max={20 - i} > {'reaction'}_{'A'}{i}.in")
    system(f"./sol < {'reaction'}_{'A'}{i}.in > {'reaction'}_{'A'}{i}.ans")

for i in range(3, 5):
    system(f"python3 ./file/equal.py > {'reaction'}_{'B'}{i}.in")
    system(f"./sol < {'reaction'}_{'B'}{i}.in > {'reaction'}_{'B'}{i}.ans")

for i in range(5, 8):
    system(f"./gen --n={300000} --c={choice(range(-3, 3))} --min={-10000000 + i} --max={10000000 - i} > {'reaction'}_{'C'}{i}.in")
    system(f"./sol < {'reaction'}_{'C'}{i}.in > {'reaction'}_{'C'}{i}.ans")

system("python3 ./file/other.py > reaction_C8.in")
system("./sol < reaction_C8.in > reaction_C8.ans")
