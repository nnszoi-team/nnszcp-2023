#include <iostream>
#include <queue>
#include <stack>
#include <vector>

class Spfa {
private:
	int n;
	std::vector<std::vector<std::pair<int, int>>> ed;

public:
	std::vector<int> dis;

private:
	std::vector<bool> vis;

public:
	void spfa(int s) {
		dis[s] = 0, vis[s] = true;
		std::queue<int> q;
		q.push(s);
		while (!q.empty()) {
			int x = q.front();
			q.pop(), vis[x] = false;
			for (auto [i, w] : ed[x])
				if (dis[i] > dis[x] + w) {
					dis[i] = dis[x] + w;
					if (vis[i] == false) q.push(i), vis[i] = true;
				}
		}
	}

	void add_edge(int u, int v, int w) { ed[u].push_back({v, w}); }

	Spfa(int n) : n(n), ed(n + 1), dis(n + 1, 0x3f3f3f3f), vis(n + 1, false) {}
};

class Twosat {
private:
	int count, color_count, n;
	std::stack<int> stack;
	std::vector<bool> vis;

public:
	std::vector<int> id, low, color;
	std::vector<std::vector<int>> ed;

	void tarjan(int x) {
		stack.push(x);
		vis[x] = true;
		id[x] = low[x] = ++count;
		for (auto i : ed[x]) {
			if (!id[i]) {
				tarjan(i);
				low[x] = std::min(low[x], low[i]);
			} else if (vis[i])
				low[x] = std::min(low[x], id[i]);
		}
		if (id[x] == low[x]) {
			++color_count;
			while (true) {
				int top = stack.top();
				vis[top] = false;
				stack.pop();
				color[top] = color_count;
				if (top == x) break;
			}
		}
	}

	void twosat() {
		for (int i = 0; i < n; ++i)
			if (id[i] == 0) tarjan(i);
	}

	void add_edge(int u, int v) { ed[u].push_back(v), ed[v].push_back(u); }

	Twosat(int n)
		: count(0),
		  color_count(0),
		  n(n),
		  vis(n),
		  id(n),
		  low(n),
		  color(n),
		  ed(n) {}
};

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	clock_t begin = clock();
	int n, q;
	std::cin >> n >> q;
	std::cerr << "input n = " << n << ' ' << "q = " << q << '\n';

	std::vector<int> answer(n + 1, 1);
	std::vector<std::pair<int, int>> cst[4];

	for (int i = 1; i <= q; ++i) {
		int l, r, v;
		std::cin >> l >> r >> v;
		cst[v].push_back({l, r});
	}

	Spfa G(n);

	for (int i = 1; i <= n; ++i)
		G.add_edge(i - 1, i, 1), G.add_edge(i, i - 1, 0);
	for (auto [l, r] : cst[0]) G.add_edge(r, l - 1, -2);
	for (auto [l, r] : cst[1]) G.add_edge(r, l - 1, 0), G.add_edge(l - 1, r, 0);
	for (auto [l, r] : cst[2])
		G.add_edge(l - 1, r, 1), G.add_edge(r, l - 1, -1);
	for (auto [l, r] : cst[3]) G.add_edge(r, l - 1, 0), G.add_edge(l - 1, r, 0);

	G.spfa(0);

	for (int i = 1; i <= n; ++i) {
		int diff = G.dis[i] - G.dis[i - 1];
		if (diff == 1) answer[i] = 2;
	}

	Twosat H(2 * (n + 1));

	for (auto [l, r] : cst[1])
		H.add_edge(2 * (l - 1), 2 * r), H.add_edge(2 * (l - 1) + 1, 2 * r + 1);

	for (auto [l, r] : cst[3])
		H.add_edge(2 * (l - 1) + 1, 2 * r), H.add_edge(2 * (l - 1), 2 * r + 1);

	H.twosat();

	for (int i = 2; i <= 2 * n; i += 2) {
		if (answer[i / 2] == 2) continue;
		bool f1 = H.color[i] < H.color[i + 1];
		bool f2 = H.color[i - 2] < H.color[i - 1];
		if (f1 == f2) {
			answer[i / 2] = 1;
		} else {
			answer[i / 2] = 3;
		}
	}

	for (int i = 1; i <= n; ++i) std::cout << answer[i] << " \n"[i == n];

	std::cerr << "solution used time "
			  << (double)(clock() - begin) / CLOCKS_PER_SEC << " ms" << '\n';

	return 0;
}
