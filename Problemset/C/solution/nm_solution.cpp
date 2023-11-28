#include <algorithm>
#include <iostream>
#include <vector>

int main() {
	std::cin.tie(nullptr)->std::ios::sync_with_stdio(false);
	int n, m;
	std::cin >> n >> m;
	std::vector<int> h(n), s(m);
	for (auto &i : h)
		std::cin >> i;
	for (auto &j : s)
		std::cin >> j;

	std::sort(h.begin(), h.end());
	for (auto i : s) {
		int p = 0;
		long long answer = 0;
		for (int j = 1; j < n; ++j) {
			while (h[j] - h[p] > i)
				++p;
			answer += j - p;
		}
		std::cout << answer << '\n';
	}

	return 0;
}