#include <cstdio>

#include "testlib.h"

template <typename T>
void fast_write(const T &num);

int main(int argc, char *argv[]) {
	registerGen(argc, argv, 1);

	int n = opt<int>("n"), m = opt<int>("m"), l = 1, r = 1e9;

	fast_write(n);
	putchar(' ');
	fast_write(m);
	putchar('\n');

	for (int i = 0; i < n; ++i) {
		fast_write(rnd.next(l, r));
		putchar(' ');
	}
	putchar('\n');

	for (int i = 0; i < m; ++i) {
		fast_write(rnd.next(l, r));
		putchar(' ');
	}

	return 0;
}

template <typename T>
void fast_write(const T &num) {
	if (num > 9) fast_write(num / 10);
	putchar(num % 10 + 48);
}
