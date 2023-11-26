from random import *
from math import *


[a, b] = [(2 ** randint(1, 23)) - 1, (2 ** randint(1, 23)) - 1]
[c, d] = [(2 ** randint(1, 23)) - 1, (2 ** randint(1, 23)) - 1]

if a > b:
    a, b = b, a
if c > d:
    c, d = d, c

p = 2
print(p, a, b, c, d)
