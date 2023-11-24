#include <algorithm>
#include <iostream>
#include <vector>

class SegmentTree {
  private:
	struct Node {
		Node *lc, *rc;
		int l, r;
		int sum;

		Node(const int l = 0, const int r = 0)
			: lc(nullptr), rc(nullptr), l(l), r(r), sum(0) {}

		void push_up() {
			this->sum = 0;
			if (this->lc) this->sum += this->lc->sum;
			if (this->rc) this->sum += this->rc->sum;
		}
	};

	Node *root;

	void build(Node *&cur, const int l, const int r) {
		cur = new Node(l, r);
		if (l == r) return;

		int mid = (l + r) >> 1;
		build(cur->lc, l, mid);
		build(cur->rc, mid + 1, r);
	}

	void modify(Node *cur, const int idx) {
		if (cur->l == cur->r) {
			cur->sum = 1;
			return;
		}

		int mid = (cur->l + cur->r) >> 1;
		modify(idx <= mid ? cur->lc : cur->rc, idx);
		cur->push_up();
	}

	int query(Node *cur, const int l, const int r) const {
		if (l <= cur->l && cur->r <= r) return cur->sum;

		int mid = (cur->l + cur->r) >> 1;
		int res = 0;
		if (l <= mid) res += query(cur->lc, l, r);
		if (r > mid) res += query(cur->rc, l, r);
		return res;
	}

	void del(Node *&cur) {
		if (!cur) return;
		del(cur->lc), del(cur->rc);
		delete cur;
		cur = nullptr;
	}

  public:
	SegmentTree() : root(nullptr) {}
	SegmentTree(const int n) : root(nullptr) { build(root, 1, n); }
	~SegmentTree() { del(root); }
	void modify(const int idx) { modify(root, idx); }
	int query(const int l, const int r) const { return query(root, l, r); }
};

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	std::cin >> n;
	std::vector<int> a(n);
	for (int &i : a)
		std::cin >> i;

	long long ans = 0;
	for (int i = 1; i < n; ++i) {
		if (a[i] <= a[0]) continue;

		std::swap(a[0], a[i]);
		++ans;
	}

	std::vector<int> b = a;
	std::sort(b.begin(), b.end());
	b.erase(std::unique(b.begin(), b.end()), b.end());

	int m = b.size();
	SegmentTree segment_tree(m);
	segment_tree.modify(m);
	for (int i = 1; i < n; ++i) {
		int idx = std::lower_bound(b.begin(), b.end(), a[i]) - b.begin() + 1;
		segment_tree.modify(idx);
		ans += segment_tree.query(idx + 1, m);
	}

	std::cout << "YES\n" << ans << '\n';

	return 0;
}