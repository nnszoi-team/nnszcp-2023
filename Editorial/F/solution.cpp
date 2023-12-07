#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

int main() {
	
	std::vector<int> l(7);
	for (int i = 0; i < 7; ++i)
		std::cin >> l[i];
	
	int n, m; std::cin >> n >> m;
	std::vector<std::tuple<int, int, int>> a(n);
	for (int i = 0; i < n; ++i) {
		int s = 0;
		for (int j = 0; j < 7; ++j) {
			int v;
			std::cin >> v;

			s += v;
			if (j == 6 || v < l[j])
				continue;
			
			++std::get<1>(a[i]);
			std::get<2>(a[i]) |= 1 << (5 - j);
		}
		std::get<0>(a[i]) = s >= l[6];
	}
	
	std::sort(a.begin(), a.end(), std::greater<std::tuple<int, int, int>>());
	while (m < n && a[m] == a[m - 1]) ++m;
	
	std::cout << m << std::endl;
	
	return 0;
}
