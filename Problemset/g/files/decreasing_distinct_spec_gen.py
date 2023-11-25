from random import *
n = randint(199995, 200000)
a = set()

while len(a) < n:
    a.add(randint(1, 1000000000))

a = list(a)
a.sort(reverse = True)

for i in range(randint(0, 5)):
    l, r = randint(0, n - 1), randint(0, n - 1)
    a[l], a[r] = a[r], a[l]

print(n)
for i in range(n - 1):
    print(a[i], end = ' ')

print(a[n - 1])
