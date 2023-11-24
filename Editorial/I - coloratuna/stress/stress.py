from os import *
from random import *

while True:
    system(f"./generator --n={randint(40000, 50000)} --q={randint(40000, 50000)} --p={randint(10, 20)} --t={randint(1, 30)} --only=0 > ./data.in")
    system(f"./solution < ./data.in > ./data.out")
    if system("./checker ./data.in ./data.out ./data.ans"):
        break
 