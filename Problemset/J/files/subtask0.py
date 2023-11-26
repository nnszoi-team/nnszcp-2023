from random import *
p = 10000000
[a, b] = [randint(1, 1000), randint(1, 1000)]
[c, d] = [randint(1, 1000), randint(1, 1000)]
if a > b:
    a, b = b, a
if c > d:
    c, d = d, c
print(p, a, b, c, d)
