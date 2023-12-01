#include <iomanip>
#include <iostream>
#include <tuple>
#include <vector>

int main() {
	std::cin.tie(nullptr)->std::ios::sync_with_stdio(false);

	clock_t begin = clock();

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
		std::vector<int> visit(n), color(n, -1), finish(n), stack;
		int time = 0, scc = 0;
		auto dfs1 = [&](auto self, int x) -> void {
			visit[x] = 1;
			for (const auto &i : ed[x])
				if (visit[i] == 0) self(self, i);
			finish[x] = ++time;
			stack.push_back(x);
		};
		for (int i = 0; i < n; ++i)
			if (visit[i] == 0) dfs1(dfs1, i);
		std::vector<std::vector<int>> red(n);
		for (int i = 0; i < n; ++i)
			for (const auto &j : ed[i]) red[j].push_back(i);
		auto dfs2 = [&](auto self, int x) -> void {
			color[x] = scc;
			for (const auto &i : red[x])
				if (color[i] == -1) self(self, i);
		};
		while (!stack.empty()) {
			int x = stack.back();
			stack.pop_back();
			if (color[x] == -1) {
				dfs2(dfs2, x);
				++scc;
			}
		}
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

	std::cerr << 1.0 * (clock() - begin) / CLOCKS_PER_SEC << '\n';

	return 0;
}
