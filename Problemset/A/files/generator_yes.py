from random import sample, randint
from string import ascii_lowercase

base = ascii_lowercase * 5

s = "".join(sample(base, randint(1, 100)))
while "nnsz" not in s:
    s = "".join(sample(base, randint(1, 100)))

print(s)
