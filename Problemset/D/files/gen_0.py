from random import * 

T = 100000

print(T)

r = [int(i) for i in range(1, 10001)]

shuffle(r)

for i in range(T):
    print(r[i % 10000], 1)
