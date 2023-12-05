#include <bitset>
#include <iostream>
#include <tuple>
#include <vector>

std::bitset<2001> matrix[2000];

int main() {
	std::cin.tie(nullptr)->std::ios::sync_with_stdio(false);

	int n, q;
	std::cin >> n >> q;
	std::vector<int> answer(n);
	std::vector<std::tuple<int, int, int>> constraint(q);

	for (auto &[l, r, v] : constraint) std::cin >> l >> r >> v, --l;

	std::vector<int> mark(n + 1);
	for (int i = 0; i < q; ++i) {
		auto [l, r, v] = constraint[i];
		switch (v) {
			case 1: {
				matrix[i][n] = false;
				for (int j = l; j < r; ++j) matrix[i][j] = true;
				++mark[l], --mark[r];
				break;
			}
			case 2: {
				matrix[i][n] = true;
				for (int j = l; j < r; ++j) matrix[i][j] = true;
				++mark[l], --mark[r];
				break;
			}
		}
	}

	bool ok = true;

	for (int i = 0; i < n; ++i) mark[i + 1] += mark[i];
	mark.insert(mark.begin(), 0), mark.pop_back();
	for (auto &i : mark) i = (bool)i;
	for (int i = 0; i < n; ++i) mark[i + 1] += mark[i];

	for (auto [l, r, v] : constraint)
		if (v == 0 && mark[r] - mark[l] == r - l) ok = false;

	auto sol = [&](int n, int q) -> std::vector<bool> {
		int p = 0;
		std::vector<bool> ans(n, false);
		std::vector<std::pair<int, int>> related;
		for (int i = 0; i < n; i++) {
			int cur = p;
			while (cur < q && !matrix[cur].test(i)) cur++;
			if (cur >= q) continue;
			if (cur != p) swap(matrix[cur], matrix[p]);
			for (int j = 0; j < q; j++)
				if (p != j && matrix[j].test(i)) matrix[j] ^= matrix[p];
			related.emplace_back(i, p);
			++p;
		}
		for (auto [pos, id] : related) ans[pos] = matrix[id].test(n);
		return ans;
	}(n, q);

	for (int i = 0; i < n; ++i)
		if (mark[i + 1] - mark[i]) answer[i] = sol[i] ? 2 : 1;

	if (ok == false) answer = std::vector<int>(n, -1);

	for (int i = 0; i < n; ++i) std::cout << answer[i] << " \n"[i == n - 1];

	return 0;
}
