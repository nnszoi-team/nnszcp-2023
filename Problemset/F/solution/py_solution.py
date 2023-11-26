for test_case in range(int(input())):
    a, b = [ int(i) for i in input().split() ]
    k = a / b
    ans = max((k * k / 4 + 1) ** 2, k * k + 1)
    print(ans)
