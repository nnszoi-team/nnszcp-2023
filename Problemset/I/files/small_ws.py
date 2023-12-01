import random

n, q = random.randint(8, 10), random.randint(8, 10)
print(n, q)

bound = random.randint(2, int(n / 1.2))

a = [random.randint(0, bound) for _ in range(n)]


for i in range(n):
    if a[i] > 0:
        a[i] = random.randint(1, 2)

s = [0] * (n + 1)
for i in range(n):
    s[i + 1] = s[i]
    if a[i] == 0:
        s[i + 1] += 1

t = [0] * (n + 1)
for i in range(n):
    t[i + 1] = t[i]
    if a[i] == 2:
        t[i + 1] += 1

for i in range(q):
    l, r = random.randint(1, n), random.randint(1, n)
    if l > r:
        l, r = r, l
    v = 0
    if s[r] - s[l - 1] == 0:
        if (t[r] - t[l - 1]) % 2 == 1:
            v = 2
        else:
            v = 1
    print(l, r, v)
