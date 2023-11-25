import random
n = random.randint(199900, 200000)
a = [int(random.randint(1, 100000000)) for i in range(1000)]
while len(a) < n:
    p = random.randint(0, len(a) - 1)
    a.append(a[p])

a.sort(reverse = True)

for i in range(1000):
    l, r = random.randint(0, n - 1), random.randint(0, n - 1)
    a[l], a[r] = a[r], a[l]

print(n)
for i in range(n - 1):
    print(a[i], end = ' ')

print(a[n - 1])
