from random import *
n = randint(190000, 200000)
a = set()

while len(a) < n:
    a.add(randint(1, 1000000000))

a = list(a)
shuffle(a)

print(n)
for i in range(n - 1):
    print(a[i], end = ' ')

print(a[n - 1])
