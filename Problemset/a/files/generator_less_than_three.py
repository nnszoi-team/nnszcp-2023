from random import sample, randint
from string import ascii_lowercase

base = ascii_lowercase

s = "".join(sample(base, randint(1, 3)))

print(s)
