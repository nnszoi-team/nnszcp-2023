from random import *
Inf = 1000000
[a, b] = [randint(1, Inf), randint(1, Inf)]
[c, d] = [randint(1, Inf), randint(1, Inf)]
if a > b:
    a, b = b, a
if c > d:
    c, d = d, c
p = max(b, d) * 4
print(p, a, b, c, d)