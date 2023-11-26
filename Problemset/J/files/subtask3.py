from random import *
from math import *
Inf = 10000000
[a, b] = [randint(1, Inf), randint(1, Inf)]
[c, d] = [randint(1, Inf), randint(1, Inf)]
if a > b:
    a, b = b, a
if c > d:
    c, d = d, c
p = (ceil(max(b, d)) ** 0.5) + 2
print(p, a, b, c, d)
