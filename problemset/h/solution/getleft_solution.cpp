#include <iostream>

const int mod = 998244353;
const int max_n = 2e5 + 10;

struct Edge {
    int next;
    int to;
};

int head[max_n];
Edge edge[max_n << 1];
int edge_idx = 0;

int fact[max_n << 1];
int size[max_n];
int dp[max_n];

void add_edge(const int from, const int to);
void solve_1(const int cur, const int fa);
void solve_2(const int cur, const int fa);

int binpow(int a, int n);
int inv(const int a);
void get_fact(const int n);
int C(const int n, const int m);

int main() {

    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n - 1; ++i) {
        int from, to;
        scanf("%d %d", &from, &to);
        add_edge(from, to);
        add_edge(to, from);
    }

    get_fact(n);
    solve_1(1, 0);
    solve_2(1, 0);

    int res = 0;
    for (int i = 1; i <= n; ++i) {
        res = (res + dp[i]) % mod;
    }

    printf("%d\n", res);

    return 0;
}

void add_edge(const int from, const int to) {
    edge[++edge_idx].to = to;
    edge[edge_idx].next = head[from];
    head[from] = edge_idx;
}

void solve_1(const int cur, const int fa) {
    size[cur] = 1;
    dp[cur] = 1;
    for (int i = head[cur]; i; i = edge[i].next) {
        int to = edge[i].to;
        if (to == fa) {
            continue;
        }

        solve_1(to, cur);
        dp[cur] = (long long)dp[cur] * dp[to] % mod * C(size[cur] + size[to] - 1, size[cur] - 1) % mod;
        size[cur] += size[to];
    }
}

void solve_2(const int cur, const int fa) {
    for (int i = head[cur]; i; i = edge[i].next) {
        int to = edge[i].to;
        if (to == fa) {
            continue;
        }

        dp[to] = (long long)dp[cur] * C(size[1] - 1, size[to] - 1) % mod * inv(C(size[1] - 1, size[1] - size[to] - 1)) % mod;
        solve_2(to, cur);
    }
}

int binpow(int a, int n) {
    int res = 1;
    for (; n; a = (long long)a * a % mod, n >>= 1) {
        if (n & 1) {
            res = (long long)res * a % mod;
        }
    }
    return res;
}

int inv(const int a) {
    return binpow(a, mod - 2);
}

void get_fact(const int n) {
    fact[0] = 1;
    for (int i = 1; i <= n << 1; ++i) {
        fact[i] = (long long)fact[i - 1] * i % mod;
    }
}

int C(const int n, const int m) {
    if (m > n) {
        return 0;
    }
    return (long long)fact[n] * inv(fact[m]) % mod * inv(fact[n - m]) % mod;
}
