#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

int main() {
	clock_t begin = clock();
	int n;
	cin >> n;
	vector<vector<int>> to(n);
	const int P = 998244353;
	for (int i = 0; i < n - 1; ++i) {
		int x, y;
		cin >> x >> y;
		--x, --y;
		to[x].push_back(y);
		to[y].push_back(x);
	}

	auto power = [&](LL a, LL b) {
		LL res = 1;
		for (LL i = b; i; i >>= 1) {
			if (i & 1) {
				res *= a;
				res %= P;
			}
			a *= a;
			a %= P;
		}
		return res;
	};

	vector<LL> fact(n + 1, 1), infact(n + 1, 1);
	for (int i = 1; i <= n; ++i) {
		fact[i] = fact[i - 1] * i % P;
		infact[i] = infact[i - 1] * power(i, P - 2) % P;
	}

	auto C = [&](int n, int m) {
		if (n < m) {
			return 0ll;
		}

		return fact[n] * infact[m] % P * infact[n - m] % P;
	};

	vector<LL> sz(n, 0), f(n, 1), g(n, 1);
	function<void(int, int)> dfs = [&](int x, int father) {
		sz[x] = 1;
		for (auto y : to[x]) {
			if (y == father) {
				continue;
			}

			dfs(y, x);
			sz[x] += sz[y];
		}

		LL s = 0;
		for (auto y : to[x]) {
			if (y == father) {
				continue;
			}
			f[x] *= f[y];
			f[x] %= P;
			s += sz[y];
			f[x] *= C(s, sz[y]);
			f[x] %= P;
		}
	};
	dfs(0, 0);

	function<void(int, int)> dfs2 = [&](int x, int father) {
		for (auto y : to[x]) {
			if (y == father) {
				continue;
			}

			LL F = g[x] * power(f[y], P - 2) % P *
				   power(C(n - 1, sz[y]), P - 2) % P;
			LL s = 0;
			for (auto z : to[y]) {
				if (z == x) {
					g[y] *= F;
					g[y] %= P;
					s += n - sz[y];
					g[y] *= C(s, n - sz[y]);
					g[y] %= P;
				} else {
					g[y] *= f[z];
					g[y] %= P;
					s += sz[z];
					g[y] *= C(s, sz[z]);
					g[y] %= P;
				}
			}
			dfs2(y, x);
		}
	};
	g[0] = f[0];
	dfs2(0, 0);

	LL ans = 0;
	for (int i = 0; i < n; ++i) {
		// cout << g[i] << endl;
		ans += g[i];
		ans %= P;
	}

	cout << ans << endl;

	std::cerr << 1.0 * (clock() - begin) / CLOCKS_PER_SEC << '\n';

	return 0;
}