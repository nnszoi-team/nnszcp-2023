# compile

import os

os.system("g++ ../file/generator.cpp -o ./generator -O3")
os.system("g++ ../file/checker.cpp -o ./checker -O3")
os.system("g++ ../solution/solution.cpp -o ./solution -O2")
