for test_case in range(int(input())):
    n, k = [int(i) for i in input().split()]

    k_min = (n - 1) * n * (n + 1) // 2
    if k < k_min:
        print(-1)
        continue

    for i in range(n):
        for j in range(n):
            print(i * n + j + (k - k_min if i == n - 1 else 0), end=" ")
        print()
