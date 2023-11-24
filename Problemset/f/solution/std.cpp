#include <bits/stdc++.h>

int main() {
	std::cin.tie(nullptr)->std::ios::sync_with_stdio(false);
	int tt;
	std::cin >> tt;
	while (tt--) {
		[]() {
			long long a, b;
			std::cin >> a >> b;
			long double ans =
				(powl(a, 4) + 8 * powl(a * b, 2) + 16 * pow(b, 4)) / (16 * powl(b, 4));
			ans = std::max(ans, (powl(a, 2) + powl(b, 2)) / powl(b, 2));
			std::cout << std::fixed << std::setprecision(12) << ans << '\n';
		}();
	}
	return 0;
}
