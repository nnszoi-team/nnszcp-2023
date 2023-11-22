#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10, mod = 998244353;
int ver[N * 2], nxt[N * 2], head[N], idx;
int fa[N], siz[N];
long long fac[N];
long long mul[N];
long long ans[N];
int n;
void add(int x, int y) {
	ver[++idx] = y;
	nxt[idx] = head[x];
	head[x] = idx;
}
int inv(long long a, long long b) {
	long long ans = 1;
	for (; b; b >>= 1) {
		if (b & 1) {
			ans = ans * a % mod;
		}
		a = a * a % mod;
	}
	return ans % mod;
}
void init() {
	fac[0] = 1;
	for (int i = 1; i <= n; ++i) {
		fac[i] = fac[i - 1] * i;
		fac[i] %= mod;
	}
}
void dfs1(int x, int f) {
	siz[x] = mul[x] = 1;
	fa[x] = f;
	for (int i = head[x]; i; i = nxt[i]) {
		int y = ver[i];
		if (y == f) {
			continue;
		}
		dfs1(y, x);
		siz[x] += siz[y];
		mul[x] *= siz[y];
		mul[x] %= mod;
		mul[x] *= mul[y];
		mul[x] %= mod;
	}
}
void dfs2(int x, int f) {
	for (int i = head[x]; i; i = nxt[i]) {
		int y = ver[i];
		if (y == f) {
			continue;
		}
		ans[y] = ans[x] * siz[y] % mod * inv(n - siz[y], mod - 2) % mod;
		ans[y] %= mod;
		dfs2(y, x);
	}
}
int main() {
	cin >> n;
	init();
	for (int i = 1; i < n; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		add(x, y);
		add(y, x);
	}
	dfs1(1, 0);
	ans[1] = fac[siz[1] - 1] * inv(mul[1], mod - 2) % mod;
	dfs2(1, 0);
	long long res = 0;
	for (int i = 1; i <= n; ++i) {
		res += ans[i];
		res %= mod;
	}
	cout << res;
}