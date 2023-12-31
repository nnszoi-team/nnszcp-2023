global MOD, graph, inv, fact, fact_inv, fa, order, size, dp

def get_fact(n: int) -> None:
    inv[1] = 1
    for i in range(2, n + 1):
        inv[i] = (MOD - MOD // i) * inv[MOD % i] % MOD

    fact[0] = 1
    for i in range(1, n + 1):
        fact[i] = fact[i - 1] * i % MOD
    
    fact_inv[n] = pow(fact[n], MOD - 2, MOD)
    for i in range(n - 1, -1, -1):
        fact_inv[i] = fact_inv[i + 1] * (i + 1) % MOD

def C(n: int, m: int) -> int:
    return fact[n] * fact_inv[m] * fact_inv[n - m] % MOD

def bfs() -> None:
    order.append(0)
    for cur in order:
        for to in graph[cur]:
            if to == fa[cur]:
                continue
            fa[to] = cur
            order.append(to)

def solve_1() -> None:
    for u in reversed(order[1:]):
        v = fa[u]
        dp[v] = dp[v] * dp[u] * C(size[v] + size[u] - 1, size[v] - 1) % MOD
        size[v] += size[u]

def solve_2() -> None:
    for u in order:
        for v in graph[u]:
            if v == fa[u]:
                continue
            dp[v] = dp[u] * size[v] * inv[size[0] - size[v]] % MOD


if __name__ == "__main__":
    
    MOD = 998244353
    n = int(input())
    inv = [0] * (n + 1)
    fact = [0] * (n + 1)
    fact_inv = [0] * (n + 1)
    get_fact(n)

    graph = [[] for _ in range(n)]
    for i in range(n - 1):
        u, v = [int(i) for i in input().split()]
        u -= 1; v -= 1
        graph[u].append(v)
        graph[v].append(u)

    fa = [-1] * n; order = []
    bfs()

    size = [1] * n; dp = [1] * n
    solve_1(); solve_2()

    print(sum(dp) % MOD)
