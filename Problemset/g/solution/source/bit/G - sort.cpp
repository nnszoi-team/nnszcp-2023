#include <iostream>
#include <vector>
#include <algorithm>

class Bit {
private:

	int n;
	std::vector<int> bit;

	int query(const int idx) const {
		int res = 0;
		for (int i = idx; i; i -= i & -i)
			res += bit[i];
		return res;
	}

public:

	Bit(const int n = 0) : n(n), bit(std::vector<int>(n + 1)) {}

	void add(const int idx) {
		for (int i = idx; i <= n; i += i & -i)
			++bit[i];
	}

	int query(const int l, const int r) const {
		return query(r) - query(l - 1);
	}
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

	std::vector<int> b = a;
	std::sort(b.begin(), b.end());
	b.erase(std::unique(b.begin(), b.end()), b.end());
	
	int m = b.size();
	std::vector<bool> added(m + 1);
	Bit bit(m);

	bit.add(m);
	added[m] = true;
	for (int i = 1; i < n; ++i) {
		int idx = std::lower_bound(b.begin(), b.end(), a[i]) - b.begin() + 1;
		if (!added[idx]) {
			bit.add(idx);
			added[idx] = true;
		}
		ans += bit.query(idx + 1, m);
	}
	
	std::cout << "YES\n" << ans << '\n';
	
	return 0;
}
