#include <bits/stdc++.h>
#define int long long

const int maxn = 2e6 + 9, modd = 998244353;
using namespace std;

vector<int> g[maxn];
int n, cnt[maxn], siz[maxn], fac[maxn], ans;

int qp(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) {
			res = (res * a) % modd;
		}
		a = (a * a) % modd;
		b >>= 1;
	}
	return res % modd;
}

inline int inv(int x) { return qp(x, modd - 2); }

inline int C(int top, int bottom) {
	// cerr<<"C : "<<top<<' '<<bottom<<'
	// '<<fac[bottom]*inv(fac[top]*fac[bottom-top]%modd)%modd<<'\n';
	return fac[bottom] * inv(fac[top] * fac[bottom - top] % modd) % modd;
}

void init(int u, int f) {
	cnt[u] = 1, siz[u] = 0;
	for (int v : g[u]) {
		if (v != f) {
			init(v, u);
			cnt[u] =
				(cnt[u] * cnt[v] % modd) * C(siz[u], siz[u] + siz[v]) % modd;
			// cerr<<cnt[u]<<' '<<siz[u]<<' '<<siz[v]<<'\n';
			siz[u] += siz[v];
		}
	}
	siz[u]++;
}

void dfs(int u, int f) {
	ans = (ans + cnt[u]) % modd;
	for (int v : g[u]) {
		if (v != f) {
			//      int delta = siz[u] - siz[v];
			int newcnt =
				cnt[u] *
				inv(cnt[v] * C(siz[u] - siz[v] - 1, siz[u] - 1) % modd) % modd;
			//      cerr<<"newcnt:"<<newcnt<<'\n';

			cnt[v] =
				(cnt[v] * newcnt % modd) * C(siz[v] - 1, siz[u] - 1) % modd;
			// cerr<<v<<' '<<cnt[v]<<"(new)\n";
			siz[v] = siz[u];

			dfs(v, u);
		}
	}
}

signed main() {
	clock_t begin = clock();
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);  // fast read
	cin >> n;
	for (int i = 1, u, v; i < n; ++i) {
		cin >> u >> v;
		g[u].push_back(v), g[v].push_back(u);
	}

	fac[0] = 1;
	for (int i = 1; i <= n; ++i) fac[i] = fac[i - 1] * i % modd;

	init(1, 0);
	// cerr<<cnt[1]<<'\n';
	dfs(1, 0);

	cout << ans;

	std::cerr << 1.0 * (clock() - begin) / CLOCKS_PER_SEC << '\n';

	return 0;
}