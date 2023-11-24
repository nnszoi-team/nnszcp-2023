#include <iostream>
#include <vector>

int main() {
	int n;
	std::cin >> n;

	std::vector<std::vector<int>> ed(n);
	for (int i = 1; i < n; ++i) {
		int u, v;
		std::cin >> u >> v;
		--u, --v;
		ed[u].push_back(v), ed[v].push_back(u);
	}

	using i64 = long long;
	const i64 p = 998'244'353;

	auto pow = [&p](i64 base, i64 times) {
		i64 res = 1, cur = base % p;
		while (times) {
			if (times & 1) (res *= cur) %= p;
			(cur *= cur) %= p, times >>= 1;
		}
		return res;
	};

	std::vector<i64> fac(n + 1), inv(n + 1);
	auto inverse = [&p, &fac, &inv](i64 base) {
		return fac[base - 1] * inv[base] % p;
	};

	fac[0] = 1;
	for (i64 i = 1; i <= n; ++i) fac[i] = fac[i - 1] * i % p;
	inv[n] = pow(fac[n], p - 2);
	for (i64 i = n - 1; i >= 0; --i) inv[i] = inv[i + 1] * (i + 1) % p;

	std::vector<i64> f(n, 1ll), s(n, 1ll);

	auto dfs = [&](auto self, int x, int fa) -> void {
		i64 cur = 0;
		for (auto i : ed[x]) {
			if (i == fa) continue;
			self(self, i, x);
			s[x] += s[i];
		}
		for (auto i : ed[x]) {
			if (i == fa) continue;
			(f[x] *= f[i] * inv[s[i]] % p) %= p;
		}
		(f[x] *= fac[s[x] - 1]) %= p;
	};

	dfs(dfs, 0, -1);

	auto find = [&](auto self, int x, int fa) -> void {
		for (auto i : ed[x]) {
			if (i == fa) continue;
			(f[i] = f[x] * s[i] % p * inverse(n - s[i])) %= p;
			self(self, i, x);
		}
	};

	find(find, 0, -1);

	i64 answer = 0;
	for (auto i : f) (answer += i) %= p;
	std::cout << answer << '\n';

	return 0;
}
