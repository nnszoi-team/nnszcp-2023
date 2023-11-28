p, a, b, c, d = [int(i) for i in input().split()]

n = 500
print(n)
print("1 0 0")
print(f"1 {p} 1")
print("1 0 1")
print(f"1 {p} 0")
print("1 1 0")
print(f"1 {p - 1} 0")
print("1 1 1")
print(f"1 {p - 1} 1")

n -= 8
l, r = 3, 2

for i in range(n // 4):
    print(f"2 1 {r} 5 7")
    print(f"2 4 {l} 6 8")
    s = i * 4 + 8 + 1
    t = i * 4 + 8 + 2
    print(f"2 1 3 {s} {t}")
    print(f"2 4 2 {s} {t}")
    l = i * 4 + 8 + 3
    r = i * 4 + 8 + 4
