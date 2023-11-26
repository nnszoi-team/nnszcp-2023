n = int(input())
a = [ int(i) for i in input().split() ]
print(max(a))
print(max(a[i + 1] - a[i] for i in range(n)))
