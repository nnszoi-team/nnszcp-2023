# generate

import os

os.system("g++ ../file/checker.cpp -o ./checker -O3")
os.system("g++ ../file/generator.cpp -o ./generator -O3")
os.system("g++ ../file/validator.cpp -o ./validator -O3")
os.system("g++ ../solution/solution.cpp -o ./solution -O2")

name = "coloratuna"

# | $\textrm{Subtask 1}$ |                   $q = 0$                   | 2 pt  |
os.system(f"./generator --n={8000} --q={0} --type=0 --c=4 --only=0> {name}_{'A'}_{1}.in")

# | $\textrm{Subtask 2}$ |             $1 \le n, q \le 10$             | 13 pt |
task = 'B'
os.system(f"./generator --n={4} --q={2} --type=1 --c=6 --only=0 > {name}_{task}_{2}.in")
os.system(f"./generator --n={8} --q={6} --type=0 --c=6 --only=0 > {name}_{task}_{3}.in")
os.system(f"./generator --n={10} --q={10} --type=1 --c=6 --only=0 > {name}_{task}_{4}.in")
os.system(f"./generator --n={9} --q={10} --type=0 --c=6 --only=0 > {name}_{task}_{5}.in")

# | $\textrm{Subtask 3}$ |      $1 \le n, q \le 10^2$，$v_i = 2$       | 17 pt |
task = 'C'
os.system(f"./generator --n={97} --q={43} --type=1 --c=0 -only=0 > {name}_{task}_{6}.in")
os.system(f"./generator --n={98} --q={54} --type=0 --c=0 --only=0 > {name}_{task}_{7}.in")
os.system(f"./generator --n={100} --q={66} --type=1 --c=0 --only=0 > {name}_{task}_{8}.in")
os.system(f"./generator --n={99} --q={78} --type=0 --c=0 --only=0 > {name}_{task}_{9}.in")
os.system(f"./generator --n={99} --q={55} --type=1 --c=0 --only=0 > {name}_{task}_{10}.in")
os.system(f"./generator --n={1} --q={87} --type=1 --c=0 --only=0 > {name}_{task}_{11}.in")

# | $\textrm{Subtask 4}$ | $1 \le n, q \le {10}^3$，$v_i \in \{1, 3\}$ | 27 pt |
task = 'D'
os.system(f"./generator --n={1000} --q={1000} --type=1 --c=0 --only=1 > {name}_{task}_{12}.in")
os.system(f"./generator --n={999} --q={1000} --type=1 --c=0 --only=1 > {name}_{task}_{13}.in")
os.system(f"./generator --n={999} --q={990} --type=1 --c=0 --only=1 > {name}_{task}_{14}.in")
os.system(f"./generator --n={998} --q={991} --type=1 --c=0 --only=1 > {name}_{task}_{15}.in")
os.system(f"./generator --n={997} --q={995} --type=1 --c=0 --only=1 > {name}_{task}_{16}.in")
os.system(f"./generator --n={998} --q={991} --type=1 --c=100000000 --only=0 > {name}_{task}_{17}.in")
os.system(f"./generator --n={997} --q={995} --type=1 --c=100000000 --only=0 > {name}_{task}_{18}.in")
os.system(f"./generator --n={998} --q={991} --type=1 --c=100000000 --only=0 > {name}_{task}_{19}.in")
os.system(f"./generator --n={997} --q={995} --type=0 --c=100000000 --only=0 > {name}_{task}_{20}.in")

# | $\textrm{Subtask 5}$ |       $1 \le n, q \le 8 \cdot {10}^3$       | 41 pt |
task = 'E'
os.system(f"./generator --n={8000} --q={8000} --type=1 --c=100 --only=0 > {name}_{task}_{21}.in")
os.system(f"./generator --n={7999} --q={7000} --type=0 --c=100 --only=0 > {name}_{task}_{22}.in")
os.system(f"./generator --n={7999} --q={7990} --type=1 --c=10 --only=0 > {name}_{task}_{23}.in")
os.system(f"./generator --n={6998} --q={7991} --type=0 --c=100 --only=0 > {name}_{task}_{24}.in")
os.system(f"./generator --n={6997} --q={7995} --type=1 --c=100 --only=0 > {name}_{task}_{25}.in")
os.system(f"./generator --n={50} --q={7991} --type=1 --c=100 --only=0 > {name}_{task}_{26}.in")
os.system(f"./generator --n={7997} --q={8000} --type=1 --c=1000 --only=0 > {name}_{task}_{27}.in")
os.system(f"./generator --n={100} --q={7991} --type=0 --c=10000 --only=0 > {name}_{task}_{28}.in")
os.system(f"./generator --n={7996} --q={7995} --type=1 --c=2000 --only=0 > {name}_{task}_{29}.in")
os.system(f"./generator --n={100} --q={8000} --type=0 --c=10000 --only=0 > {name}_{task}_{30}.in")
os.system(f"./generator --n={7999} --q={8000} --type=1 --c=1000 --only=0 > {name}_{task}_{31}.in")
os.system(f"./generator --n={7998} --q={7995} --type=1 --c=2000 --only=0 > {name}_{task}_{32}.in")
os.system(f"./generator --n={100} --q={7999} --type=0 --c=10 --only=0 > {name}_{task}_{33}.in")
os.system(f"./generator --n={7999} --q={6999} --type=1 --c=100 --only=0 > {name}_{task}_{34}.in")
os.system(f"./generator --n={7999} --q={7000} --type=1 --c=500 --only=0 > {name}_{task}_{35}.in")
os.system(f"./generator --n={6000} --q={8000} --type=1 --c=600 --only=0 > {name}_{task}_{36}.in")
os.system(f"./generator --n={6001} --q={7995} --type=1 --c=2000 --only=0 > {name}_{task}_{37}.in")
os.system(f"./generator --n={6002} --q={7999} --type=0 --c=10 --only=0 > {name}_{task}_{38}.in")
os.system(f"./generator --n={7000} --q={6999} --type=1 --c=700 --only=0 > {name}_{task}_{39}.in")
os.system(f"./generator --n={7550} --q={7000} --type=0 --c=5 --only=0 > {name}_{task}_{40}.in")
os.system(f"./generator --n={6000} --q={7999} --type=1 --c=900 --only=0 > {name}_{task}_{41}.in")
os.system(f"./generator --n={6001} --q={7994} --type=1 --c=2000 --only=0 > {name}_{task}_{42}.in")
os.system(f"./generator --n={6002} --q={7998} --type=0 --c=5 --only=0 > {name}_{task}_{43}.in")
os.system(f"./generator --n={7000} --q={6998} --type=1 --c=100 --only=0 > {name}_{task}_{44}.in")
os.system(f"./generator --n={7550} --q={6999} --type=0 --c=10 --only=0 > {name}_{task}_{45}.in")

dic = []
dic.append('A')
for i in range(2, 6):
    dic.append('B')
for i in range(6, 12):
    dic.append('C')
for i in range(12, 21):
    dic.append('D')
for i in range(21, 46):
    dic.append('E')

for i in range(45):
    os.system(f"./solution < {name}_{dic[i]}_{i + 1}.in > {name}_{dic[i]}_{i + 1}.ans")

os.system(f"rm ./checker")
os.system(f"rm ./generator")
os.system(f"rm ./solution")

for i in range(45):
    os.system(f"./validator < {name}_{dic[i]}_{i + 1}.in")

os.system(f"rm ./validator")

