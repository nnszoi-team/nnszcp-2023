#include <string>

#include "testlib.h"

using namespace std;

const int N = 100000, Q = 100000;

int main(int argc, char *argv[]) {
	registerValidation(argc, argv);

	int n = inf.readInt(1, N, "n");
	inf.readSpace();
	int q = inf.readInt(0, Q, "q");
	inf.readEoln();

	for (int i = 1; i <= q; ++i) {
		int l = inf.readInt(1, n, "l_i");
		inf.readSpace();
		int r = inf.readInt(1, n, "r_i");
		inf.readSpace();
		int v = inf.readInt(0, 3, "v_i");

		ensuref(l <= r, "conatraint %d is not valid : l_i = %d > r_i = %d", i, l, r);
		inf.readEoln();
	}

	inf.readEof();
	return 0;
}
