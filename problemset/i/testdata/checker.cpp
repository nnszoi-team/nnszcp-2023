#include <string>

#include "testlib.h"

using namespace std;

const int N = 20000, Q = 20000;

int main(int argc, char* argv[]) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	clock_t begin = clock();
	registerTestlibCmd(argc, argv);

	int n = inf.readInt(1, N, "n"), q = inf.readInt(0, Q, "q");

	std::vector<int> a(n + 1);
	for (int i = 1; i <= n; ++i) {
		int x = ouf.readInt(1, 3, "a_i");
		a[i] = x;
	}

	int cnt[n + 1][4];
	memset(cnt, 0, sizeof(cnt));
	for (int i = 1; i <= n; ++i) {
		cnt[i][0] = cnt[i - 1][0];
		cnt[i][1] = cnt[i - 1][1];
		cnt[i][2] = cnt[i - 1][2];
		cnt[i][3] = cnt[i - 1][3];
		++cnt[i][a[i]];
	}

	for (int i = 1; i <= q; ++i) {
		int l = inf.readInt(1, n, "l_i");
		int r = inf.readInt(1, n, "r_i");
		int v = inf.readInt(0, 3, "v_i");
		if (l > r)
			quitf(_fail,
				  "constraint %d : l_%d = %d should not be greater than l_%d = "
				  "%d",
				  i, i, l, i, r);

		int res[] = {cnt[r][0] - cnt[l - 1][0], cnt[r][1] - cnt[l - 1][1],
					 cnt[r][2] - cnt[l - 1][2], cnt[r][3] - cnt[l - 1][3]};

		switch (v) {
			case 0: {
				if (res[2] < 2)
					quitf(_wa, "constraint %d : v_%d = %d is not satisfied", i,
						  i, v);
				break;
			}
			case 1: {
				if (res[2] != 0 || res[3] % 2 != 0)
					quitf(_wa, "constraint %d : v_%d = %d is not satisfied", i,
						  i, v);
				break;
			}
			case 2: {
				if (res[2] != 1)
					quitf(_wa, "constraint %d : v_%d = %d is not satisfied", i,
						  i, v);
				break;
			}
			case 3: {
				if (res[2] != 0 || res[3] % 2 != 1)
					quitf(_wa, "constraint %d : v_%d = %d is not satisfied", i,
						  i, v);
				break;
			}
		}
	}

	quitf(_ok,
		  "solution correct : n = %d, q = "
		  "%d\nchecker used time = %lf ms",
		  n, q, (double)(clock() - begin) / CLOCKS_PER_SEC);

	return 0;
}
