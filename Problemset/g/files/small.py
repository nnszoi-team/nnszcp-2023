from random import *
n = randint(900, 1000)
a = [int(randint(1, 100000000)) for i in range(300)]
while len(a) < n:
    p = randint(0, len(a) - 1)
    a.append(a[p])

print(n)
for i in range(n - 1):
    print(a[i], end = ' ')

print(a[n - 1])
