from bisect import bisect_right

n, m = [ int(i) for i in input().split() ]
h = [ int(i) for i in input().split() ]
s = [ int(i) for i in input().split() ]
dh = sorted([ abs(h[i] - h[j]) for i in range(n) for j in range(i) ])

for i in s:
    print(bisect_right(dh, i))
