import random
import sys

argv = sys.argv[1:7]

n, q, wl, wr, z, o = [int(i) for i in argv]

a = [int(0) for _ in range(z)] + [int(1) for _ in range(o)] + [int(2) for _ in range(n - o - z)]
random.shuffle(a)

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

c = []

for i in range(q):
    cw = random.randint(wl, wr)
    cl = random.randint(1, n - cw + 1)
    cr = cl + cw - 1
    cv = 0
    if s[cr] - s[cl - 1] == 0:
        if (t[cr] - t[cl - 1]) % 2 == 1:
            cv = 2
        else:
            cv = 1
    c.append([cl, cr, cv])

random.shuffle(c)

print(n, q)
for i in c:
    print(i[0], i[1], i[2])


