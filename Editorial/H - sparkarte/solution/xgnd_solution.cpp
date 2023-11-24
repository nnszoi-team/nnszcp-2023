#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 500005, INF = 0x3f3f3f3f, mod = 998244353;
int n, m;
int fac[maxn], inv[maxn];
int siz[maxn], dp[maxn], f[maxn];
vector<int> g[maxn];

int qpow(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) res = (res * a) % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return res;
}

int C(int n, int m) {
	if (n < m) return 0;
	return fac[n] * inv[m] % mod * inv[n - m] % mod;
}

void dfs(int x, int fath) {
	siz[x] = 1;
	dp[x] = 1;
	int s = 0;
	for (int to : g[x]) {
		if (to == fath) continue;
		dfs(to, x);
		siz[x] += siz[to];
		s += siz[to];
		(dp[x] *= dp[to]) %= mod;
		(dp[x] *= C(s, siz[to])) %= mod;
	}
}

void dfs1(int x, int fath) {
	for (int to : g[x]) {
		if (to == fath) continue;
		f[to] = 1;
		int s = 0;
		for (int t : g[to]) {
			if (t == x) {
				s += n - siz[to];
				(f[to] *= f[x] * qpow(dp[to], mod - 2) % mod *
						  qpow(C(n - 1, siz[to]), mod - 2) % mod) %= mod;
				(f[to] *= C(s, n - siz[to])) %= mod;
			} else {
				s += siz[t];
				(f[to] *= dp[t]) %= mod;
				(f[to] *= C(s, siz[t])) %= mod;
			}
		}
		dfs1(to, x);
	}
}

signed main() {
	ios::sync_with_stdio(0);
	cin >> n;

	fac[0] = 1;
	for (int i = 1; i < maxn; i++) {
		fac[i] = fac[i - 1] * i % mod;
	}
	inv[maxn - 1] = qpow(fac[maxn - 1], mod - 2);
	for (int i = maxn - 2; i >= 0; i--) {
		inv[i] = inv[i + 1] * (i + 1) % mod;
	}

	for (int i = 1; i < n; i++) {
		int x, y;
		cin >> x >> y;
		g[x].push_back(y);
		g[y].push_back(x);
	}

	dfs(1, 0);
	f[1] = dp[1];
	dfs1(1, 0);

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		ans = (ans + f[i]) % mod;
	}

	cout << ans << endl;

	return 0;
}