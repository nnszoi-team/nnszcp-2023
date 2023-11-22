#include <iostream>
#include <algorithm>
using namespace std;

const int max_n = 2e5 + 10;

int n, m;
int a[max_n], b[max_n];
bool added[max_n];
int bit[max_n];

void add(const int idx);
int query(const int idx);

int main() {
	
	freopen("sort.in", "r", stdin);
	freopen("sort.out", "w", stdout);
	
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		b[i] = a[i];
	}
	sort(b + 1, b + n + 1);
	m = unique(b + 1, b + n + 1) - (b + 1);
	
	long long ans = 0;
	for (int i = 2; i <= n; ++i) {
		if (a[i] <= a[1]) {
			continue;
		}
		++ans;
		swap(a[i], a[1]);
	}
	
	added[m] = true;
	add(m);
	for (int i = 2; i <= n; ++i) {
		int idx = lower_bound(b + 1, b + m + 1, a[i]) - b;
		if (!added[idx]) {
			add(idx);
			added[idx] = true;
		}
		ans += query(m) - query(idx);
	}
	
	printf("YES\n%lld\n", ans);
	
	return 0;
}

void add(const int idx) {
	for (int i = idx; i <= m; i += i & -i) {
		++bit[i];
	}
}

int query(const int idx) {
	int res = 0;
	for (int i = idx; i; i -= i & -i) {
		res += bit[i];
	}
	return res;
}

