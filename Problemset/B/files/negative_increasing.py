import random

l, r = random.randint(-10000000, -1), random.randint(-10000000, -1)
if l > r:
    l, r = r, l

n = random.randint(299998, 300000)
a = [int(random.randint(l, r)) for i in range(n + 1)]
a.sort()

print(n)
for i in range(n):
    print(a[i], end=" ")
print(a[n])
