import sys
import random

T = sys.argv[0]
n = sys.argv[1]
k = sys.argv[2]

print(T)

for i in range(T):
    print(random.randint(1, n), random.randint(1, k))

print()
