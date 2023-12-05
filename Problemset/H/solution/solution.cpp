#include <iostream>
#include <vector>

const int mod = 998244353;

std::vector<std::vector<int>> graph;
std::vector<int> inv, fact, fact_inv, dp, size;

void solve_1(const int cur, const int fa);
void solve_2(const int cur, const int fa);

int binpow(int a, int n);
void prework(const int n);
int C(const int n, const int m);

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n; std::cin >> n;
    graph = std::vector<std::vector<int>>(n);
    for (int i = 0, u, v; i < n - 1; ++i) {
        std::cin >> u >> v; --u, --v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    inv = fact = fact_inv = std::vector<int>(n + 1);
    prework(n);
    
    dp = size = std::vector<int>(n);
    solve_1(0, -1); solve_2(0, -1);

    int res = 0;
    for (const int i : dp)
        res = (res + i) % mod;

    std::cout << res << std::endl;

    return 0;
}

void solve_1(const int cur, const int fa) {
    size[cur] = 1, dp[cur] = 1;
    for (const int to : graph[cur]) {
        if (to == fa) continue;

        solve_1(to, cur);
        dp[cur] = (long long)dp[cur] * dp[to] % mod * C(size[cur] + size[to] - 1, size[cur] - 1) % mod;
        size[cur] += size[to];
    }
}

void solve_2(const int cur, const int fa) {
    for (const int to : graph[cur]) {
        if (to == fa) continue;

        dp[to] = (long long)dp[cur] * size[to] % mod * inv[size[0] - size[to]] % mod;
        solve_2(to, cur);
    }
}

int binpow(int a, int n) {
    int res = 1;
    for (; n; a = (long long)a * a % mod, n >>= 1)
        if (n & 1)
            res = (long long)res * a % mod;
    return res;
}

void prework(const int n) {
    inv[1] = 1;
    for (int i = 2; i <= n; ++i) 
        inv[i] = (long long)(mod - mod / i) * inv[mod % i] % mod;

    fact[0] = fact_inv[0] = 1;
    for (int i = 1; i <= n; ++i)
        fact[i] = (long long)fact[i - 1] * i % mod;
    
    fact_inv[n] = binpow(fact[n], mod - 2);
    for (int i = n - 1; i; --i)
        fact_inv[i] = (long long)fact_inv[i + 1] * (i + 1) % mod;
}

int C(const int n, const int m) {
    return (long long)fact[n] * fact_inv[m] % mod * fact_inv[n - m] % mod;
}
