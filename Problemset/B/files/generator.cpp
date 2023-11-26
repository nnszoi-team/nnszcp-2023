#include "./testlib.h"

int main(int argc, char* argv[]) {
	registerGen(argc, argv, 1);
	int n = opt<int>("n");
	int c = opt<int>("c");
	int min = opt<int>("min");
	int max = opt<int>("max");

	std::vector<int> a(n);
	for (int& i : a) i = rnd.wnext(min, max, c);

	println(n - 1);
	for (int i = 0; i < n; ++i) std::cout << a[i] << " \n"[i + 1 == n];
	return 0;
}
