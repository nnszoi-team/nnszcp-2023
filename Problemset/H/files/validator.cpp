#include "testlib.h"

const int max_n = 2e5;

struct Dsu {
	int n;
	int fa[max_n + 10];

	Dsu(const int n = 0) : n(n) {
		for (int i = 1; i <= n; ++i) {
			fa[i] = i;
		}
	}
	int get(const int cur) {
		return fa[cur] == cur ? cur : fa[cur] = get(fa[cur]);
	}
	bool merge(const int x, const int y) {
		int fa_x = get(x), fa_y = get(y);
		if (fa_x == fa_y) {
			return false;
		}
		fa[fa_y] = fa_x;
		return true;
	}
	int cnt_block() {
		int res = 0;
		for (int i = 1; i <= n; ++i) {
			res += (fa[i] == i);
		}
		return res;
	}
};

int main(int argc, char* argv[]) {
	registerValidation(argc, argv);

	int n = inf.readInt(1, max_n, "n");
	inf.readEoln();

	Dsu dsu(n);
	for (int i = 1; i <= n - 1; ++i) {
		int from = inf.readInt(1, n, "from");
		inf.readSpace();
		int to = inf.readInt(1, n, "to");
		inf.readEoln();

		ensuref(dsu.merge(from, to), "Loop detected.");
	}

	ensuref(dsu.cnt_block() == 1, "block_num = %d.", dsu.cnt_block());

	inf.readEof();

	return 0;
}
