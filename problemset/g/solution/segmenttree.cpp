#include <iostream>
#include <algorithm>
using namespace std;

const int max_n = 2e5 + 10;

struct Node {
	int l, r;
	int sum;
};

struct SegmentTree {
	
	Node node[max_n << 2];
	
	void build(const int l, const int r, const int cur = 1);
	void update(const int idx, const int cur = 1);
	int query(const int l, const int r, const int cur = 1);
};

int n, m;
int a[max_n], b[max_n];
SegmentTree segment_tree;

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
	
	segment_tree.build(1, n);
	segment_tree.update(m);
	for (int i = 2; i <= n; ++i) {
		ans += segment_tree.query(upper_bound(b + 1, b + m + 1, a[i]) - b, m);
		segment_tree.update(lower_bound(b + 1, b + m + 1, a[i]) - b);
	}
	
	printf("YES\n%lld\n", ans);
	
	return 0;
}

void SegmentTree::build(const int l, const int r, const int cur) {
	node[cur].l = l;
	node[cur].r = r;
	if (l == r) {
		return;
	}
	
	int mid = l + r >> 1;
	build(l, mid, cur << 1);
	build(mid + 1, r, cur << 1 | 1);
}

void SegmentTree::update(const int idx, const int cur) {
	if (node[cur].l == node[cur].r) {
		node[cur].sum = 1;
		return;
	}
	
	int mid = node[cur].l + node[cur].r >> 1;
	if (idx <= mid) {
		update(idx, cur << 1);
	}
	else {
		update(idx, cur << 1 | 1);
	}
	node[cur].sum = node[cur << 1].sum + node[cur << 1 | 1].sum;
}

int SegmentTree::query(const int l, const int r, const int cur) {
	if (l <= node[cur].l && node[cur].r <= r) {
		return node[cur].sum;
	}
	
	int mid = node[cur].l + node[cur].r >> 1;
	int res = 0;
	if (l <= mid) {
		res += query(l, r, cur << 1);
	}
	if (r > mid) {
		res += query(l, r, cur << 1 | 1);
	}
	return res;
}

