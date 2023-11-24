l = [int(i) for i in input().split()]
n, m = [int(i) for i in input().split()]

a = []
for i in range(n):
    s = [int(i) for i in input().split()]
    t = [sum(s) >= l[6], 0, 0]

    for j in range(6):
        if s[j] < l[j]:
            continue
        t[1] += 1
        t[2] |= 1 << (5 - j)
    a.append(tuple(t))

a.sort(reverse=True)
while m < n and a[m] == a[m - 1]:
    m += 1

print(m)
