#include <bits/stdc++.h>

int main() {
	freopen("data.in", "w", stdout);

	int n = 50000, q = 50000;
	std::cout << n << ' ' << q << '\n';
	std::vector<int> seq(n + 1);
	for (int i = 1; i <= n; ++i) seq[i] = (rand() % 2 == 0) ? 1 : 3;
	for (int i = 1; i <= n; i += rand() % 10) seq[i] = 2;

	for (int i = 1; i <= q; ++i) {
		int l = rand() % n + 1, len = rand() % 4 + 1;
		int r = std::min(l + len - 1, n);
		int mul = 1;
		for (int j = l; j <= r; ++j) {
			(mul *= seq[j]) %= 4;
		}
		std::cout << l << ' ' << r << ' ' << mul << '\n';
	}

	return 0;
}
