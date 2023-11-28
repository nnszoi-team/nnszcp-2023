import sys
import random

T = 10
n = 500
k = 1000000000

print(T)

for i in range(T):
    print(random.randint(1, n), random.randint(1, k))
