import sys
import random

T = 10
n = 100
k = 100000

print(T)

for i in range(T):
    print(random.randint(1, n), random.randint(1, k))
