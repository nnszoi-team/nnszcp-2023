from random import *
Inf = 10000000
[a, b] = [randint(1, Inf), randint(1, Inf)]
[c, d] = [randint(1, Inf), randint(1, Inf)]
if a > b:
    a, b = b, a
if c > d:
    c, d = d, c
p = int((max(b, d) + 20) ** 0.5 + 1)
print(p, a, b, c, d)
