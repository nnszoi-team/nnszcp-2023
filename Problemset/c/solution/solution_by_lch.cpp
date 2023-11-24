#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int h[N], a[N], d[4000010], tot;
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &h[i]);
	}
	for (int i = 1; i <= m; ++i) {
		scanf("%d", &a[i]);
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = i + 1; j <= n; ++j) {
			d[++tot] = abs(h[i] - h[j]);
		}
	}
	sort(d + 1, d + tot + 1);
	for (int i = 1; i <= m; ++i) {
		int pos = upper_bound(d + 1, d + tot + 1, a[i]) - d;
		if (!d[pos]) {
			printf("%d\n", tot);
		} else {
			printf("%d\n", pos - 1);
		}
	}
}
