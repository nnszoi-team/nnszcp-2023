#include <bits/stdc++.h>
#define int long long

const int maxn = 2e5 + 9;
using namespace std;

int tot = 1, head[maxn], nxt[maxn << 1], ver[maxn << 1];
inline void addEdge(int u, int v) {
	ver[++tot] = v, nxt[tot] = head[u], head[u] = tot;
	ver[++tot] = u, nxt[tot] = head[v], head[v] = tot;
}

int deg[maxn], n;
bool disabled[maxn << 1];

int ans = 0;
void dfs(int curr) {
	if (curr >= n - 1) {
		++ans;
		ans %= 998244353;
		return;
	}

	for (int i = 1; i <= n; ++i) {
		if (deg[i] == 1) {
			// cerr<<curr<<' '<<i<<'\n';
			for (int j = head[i]; j; j = nxt[j]) {
				if (!disabled[j]) {
					int v = ver[j];
					disabled[j] = disabled[j ^ 1] = true;
					deg[i]--, deg[v]--;
					dfs(curr + 1);
					disabled[j] = disabled[j ^ 1] = false;
					deg[i]++, deg[v]++;
				}
			}
		}
	}
}

signed main() {
	clock_t begin = clock();
	cin >> n;
	for (int i = 1, u, v; i < n; ++i) {
		cin >> u >> v;
		//    g.push_back({u,v});
		addEdge(u, v);
		deg[u]++, deg[v]++;
	}

	dfs(0);
	cout << ans << '\n';
	std::cerr << (clock() - begin) << '\n';
}