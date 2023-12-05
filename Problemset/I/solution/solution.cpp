#include <iomanip>
#include <iostream>
#include <tuple>
#include <vector>

int main() {
	std::cin.tie(nullptr)->std::ios::sync_with_stdio(false);

	int n, q;
	std::cin >> n >> q;
	std::vector<int> answer(n);
	std::vector<std::tuple<int, int, int>> constraint(q);

	for (auto &[l, r, v] : constraint) std::cin >> l >> r >> v, --l;

	std::vector<std::vector<int>> ed(2 * n + 2);
	std::vector<int> mark(n + 1);
	for (auto [l, r, v] : constraint) {
		switch (v) {
			case 1: {
				ed[2 * r].push_back(2 * l);
				ed[2 * l].push_back(2 * r);
				ed[2 * r + 1].push_back(2 * l + 1);
				ed[2 * l + 1].push_back(2 * r + 1);
				++mark[l], --mark[r];
				break;
			}
			case 2: {
				ed[2 * r].push_back(2 * l + 1);
				ed[2 * l].push_back(2 * r + 1);
				ed[2 * r + 1].push_back(2 * l);
				ed[2 * l + 1].push_back(2 * r);
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

	auto color = [](const std::vector<std::vector<int>> &ed) {
		int n = ed.size();
		std::vector<int> visit(n), color(n, -1), id(n), low(n), stack;
		int count = 0, scc = 0;
		auto dfs = [&](auto self, const int x) -> void {
			id[x] = low[x] = count++;
			visit[x] = 1, stack.push_back(x);
			for (const auto &i : ed[x])
				if (visit[i] == 0)
					self(self, i), low[x] = std::min(low[x], low[i]);
				else if (visit[i] == 1)
					low[x] = std::min(low[x], id[i]);

			if (low[x] == id[x]) {
				while (stack.back() != x) {
					color[stack.back()] = scc;
					visit[stack.back()] = 2;
					stack.pop_back();
				}
				color[x] = scc;
				visit[x] = 2;
				stack.pop_back();
				++scc;
			}
		};
		for (int i = 0; i < n; ++i)
			if (visit[i] != 2) dfs(dfs, i);
		return color;
	}(ed);

	if ([](const std::vector<int> &color, const int n) {
			for (int i = 0; i <= n; ++i)
				if (color[2 * i] == color[2 * i + 1]) return true;
			return false;
		}(color, n)) {
		ok = false;
	}

	[&answer, &mark, n](const std::vector<int> &color) {
		for (int i = 0; i < n; ++i) {
			if (mark[i + 1] - mark[i] == 0) continue;
			bool f = color[2 * i] < color[2 * i + 1];
			bool g = color[2 * i + 2] < color[2 * i + 3];
			if (f != g)
				answer[i] = 2;
			else
				answer[i] = 1;
		}
	}(color);

	if (ok == false) answer = std::vector<int>(n, -1);

	for (int i = 0; i < n; ++i) std::cout << answer[i] << " \n"[i == n - 1];

	return 0;
}
