#include "./testlib.h"

int main(int argc, char* argv[]) {
	registerGen(argc, argv, 1);

	std::ios::sync_with_stdio(false);

	clock_t begin = clock();

	int n = opt<int>("n");
	int q = opt<int>("q");
	int p = opt<int>("p");
	int t = opt<int>("t");

	bool only = opt<int>("only");

	if (only) {
		std::vector<int> seq(n);
		for (int& i : seq) i = (rnd.next(0, 1) << 1) ^ 1;
		std::cout << n << ' ' << q << '\n';
		for (int i = 0; i < q; ++i) {
			int l = rnd.next(1, n), r = rnd.next(1, n);
			if (l > r) std::swap(l, r);
			int mul = 1;
			for (int j = l - 1; j < r; ++j) (mul *= seq[j]) %= 4;
			std::cout << l << ' ' << r << ' ' << mul << '\n';
		}
		std::cerr << "generator used time "
				  << (double)(clock() - begin) / CLOCKS_PER_SEC << " ms"
				  << '\n';
		return 0;
	}

	else {
		std::cout << n << ' ' << q << '\n';
		std::vector<int> seq(n + 1);
		for (int i = 1; i <= n; ++i) {
			int x = rnd.next(0, p);
			if (x == 0)
				seq[i] = 2;
			else
				seq[i] = (x % 2 == 1 ? 1 : 3);
		}
		int cnt[n + 1][4];
		memset(cnt, 0, sizeof(cnt));
		for (int i = 1; i <= n; ++i) {
			cnt[i][0] = cnt[i - 1][0];
			cnt[i][1] = cnt[i - 1][1];
			cnt[i][2] = cnt[i - 1][2];
			cnt[i][3] = cnt[i - 1][3];
			++cnt[i][seq[i]];
		}

		for (int i = 0; i < q; ++i) {
			int len = rnd.next(1, t);
			int l = rnd.next(1, n - len + 1);
			int r = std::min(l + len - 1, n);
			int x = 1;
			if (l > r) std::swap(l, r);
			int res[] = {cnt[r][0] - cnt[l - 1][0], cnt[r][1] - cnt[l - 1][1],
						 cnt[r][2] - cnt[l - 1][2], cnt[r][3] - cnt[l - 1][3]};
			if (res[2] >= 2)
				x = 0;
			else if (res[2] == 1)
				x = 2;
			else if (res[3] % 2 == 0)
				x = 1;
			else
				x = 3;
			std::cout << l << ' ' << r << ' ' << x << '\n';
		}
	}

	std::cerr << "generator used time "
			  << (double)(clock() - begin) / CLOCKS_PER_SEC << " ms" << '\n';

	return 0;
}
