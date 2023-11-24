import random

[n, m] = [random.randint(1980, 2000), random.randint(99900, 100000)]

print(n, m)

MAX = 10 ** 9

const_h = random.randint(1, MAX)
for i in range(n):
    print(const_h, end = ' ')

print()

for i in range(m):
    print(random.randint(1, MAX), end = ' ')

print()
