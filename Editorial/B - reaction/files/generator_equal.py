import random

n = random.randint(99997, 100000)
a = [int(random.randint(-10000000, 10000000)) for i in range(n + 1)]

a.sort()
print(n)
for i in range(n + 1):
    print(a[i], end = ' ')
