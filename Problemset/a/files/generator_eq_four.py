from random import sample
from string import ascii_lowercase

base = ascii_lowercase

s = "".join(sample(base, 4))

print(s)
