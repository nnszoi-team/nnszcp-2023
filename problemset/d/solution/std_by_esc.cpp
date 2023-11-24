#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
	std::vector<int> line(6);
	for (auto& i : line) std::cin >> i;
	std::reverse(line.begin(), line.end());

	int ls;
	std::cin >> ls;

	int n, m;
	std::cin >> n >> m;

	std::map<int, int, std::greater<int>> map;

	for (int i = 0; i < n; ++i) {
		int sum = 0, lev = 0;
		for (int j = 5; j >= 0; --j) {
			int x;
			std::cin >> x;
			if (x >= line[j]) lev += (1 << j);
			sum += x;
		}
		lev += (1 << (__builtin_popcount(lev) + 6));
		int x;
		std::cin >> x;
		sum += x;
		if (sum >= ls) lev += (1 << 13);
		++map[lev];
	}

	int sum = 0;
	for (auto i : map) {
		if ((sum += i.second) >= m) {
			return std::cout << sum << '\n', 0;
		}
	}

	return 0;
}
