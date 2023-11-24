#include <iostream>
#include <cstdlib>
#include <vector>

class Treap {
private:

	struct Node {
		Node *lc, *rc;
		int value, key;
		int size;

		Node(const int value = 0) : lc(nullptr), rc(nullptr), value(value), key(rand()), size(1) {}

		void upd_size() {
			this->size = 1;
			if (this->lc) this->size += this->lc->size;
			if (this->rc) this->size += this->rc->size;
		}
	};

	Node *root;
	
	void zig(Node *&cur) {
		Node *prev_lc = cur->lc;
		cur->lc = prev_lc->rc;
		prev_lc->rc = cur;

		cur = prev_lc;
		
		cur->rc->upd_size();
		cur->upd_size();
	}

	void zag(Node *&cur) {
		Node *prev_rc = cur->rc;
		cur->rc = prev_rc->lc;
		prev_rc->lc = cur;

		cur = prev_rc;

		cur->lc->upd_size();
		cur->upd_size();
	}

	void insert(Node *&cur, const int value) {
		if (!cur) {
			cur = new Node(value);
			return;
		}
		if (cur->value == value)
			return;

		if (cur->value > value) {
			insert(cur->lc, value);
			if (cur->key < cur->lc->key)
				zig(cur);
		}
		else {
			insert(cur->rc, value);
			if (cur->key < cur->rc->key)
				zag(cur);
		}
		cur->upd_size();
	}
	
	int query(const Node *cur, const int value) const {
		if (!cur)
			return 0;
		if (cur->value < value)
			return query(cur->rc, value);
		if (cur->value == value)
			return cur->rc ? cur->rc->size : 0;
		return query(cur->lc, value) + 1 + (cur->rc ? cur->rc->size : 0);
	}

	void del(Node *&cur) {
		if (!cur) return;
		del(cur->lc), del(cur->rc);
		delete cur;
		cur = nullptr;
	}

public:

	Treap() : root(nullptr) {}
	~Treap() { del(root); }
	void insert(const int value) { insert(root, value); }
	int query(const int value) const { return query(root, value); }
};

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n; std::cin >> n;
	std::vector<int> a(n);
	for (int& i : a) std::cin >> i;
	
	long long ans = 0;
	for (int i = 1; i < n; ++i) {
		if (a[i] <= a[0])
			continue;

		std::swap(a[0], a[i]);
		++ans;
	}
	
	Treap treap;
	treap.insert(a[0]);
	for (int i = 1; i < n; ++i) {
		ans += treap.query(a[i]);
		treap.insert(a[i]);
	}
	
	std::cout << "YES\n" << ans << '\n';
	
	return 0;
}
