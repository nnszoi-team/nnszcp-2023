import random
n = random.randint(190000, 200000)
a = [int(random.randint(1, 100000000)) for i in range(1000)]
while len(a) < n:
    p = random.randint(0, len(a) - 1)
    a.append(a[p])

print(n)
for i in range(n - 1):
    print(a[i], end = ' ')

print(a[n - 1])
