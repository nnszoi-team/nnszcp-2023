p, a, b, c, d = [int(i) for i in input().split()]
print(20)
print("1 0 0") # 1
print(f"1 {d} 1") # 2
print(f"1 {c} 0") # 3
print(f"1 {c} 1") # 4
print(f"2 1 2 3 4") # 5 (c, c / d)
print("1 1 0") # 6
print(f"1 {d + 1} 1") # 7
print(f"1 {c + 1} 0") # 8
print(f"1 {c + 1} 1") # 9
print(f"2 6 7 8 9") # 10 (c + 1, c / d + 1)
print(f"1 1 {b}") # 11
print(f"1 0 {a}") # 12
print(f"1 1 {a}") # 13
print(f"2 1 11 12 13") # 14 (a / b, a)
print(f"1 0 1") # 15
print(f"1 1 {b + 1}") # 16
print(f"1 0 {a + 1}") # 17
print(f"1 1 {a + 1}") # 18
print(f"2 15 16 17 18") # 19 (a / b + 1, a + 1)
print(f"2 5 10 14 19") # 20
