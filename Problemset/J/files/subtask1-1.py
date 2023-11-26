from random import *

N = 1000001

pri = []
not_prime = [False] * N

def pre(n):
    for i in range(2, n + 1):
        if not not_prime[i]:
            pri.append(i)
        for pri_j in pri:
            if i * pri_j > n:
                break
            not_prime[i * pri_j] = True
            if i % pri_j == 0:
                break

Inf = 1000000
pre(Inf)
n = len(pri)

[a, b] = [pri[randint(0, n - 1)], pri[randint(n - 100, n - 1)]]
[c, d] = [pri[randint(0, n - 1)], pri[randint(n - 100, n - 1)]]
if a > b:
    a, b = b, a
if c > d:
    c, d = d, c
p = max(b, d) + 1
print(p, a, b, c, d)
