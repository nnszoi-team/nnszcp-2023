#include <vector>

#include "testlib.h"

class Tree {
public:
	int n;
	std::vector<std::pair<int, int>> ed;

	Tree(int n) : n(n) {}
	void print() {
		std::cout << n << '\n';
		for (auto i : ed)
			std::cout << i.first + 1 << ' ' << i.second + 1 << '\n';
	}
};

Tree generate_tree(int n, int t) {
	std::vector<int> p(n);
	for (int i = 1; i < n; ++i) p[i] = rnd.wnext(i, t);
	std::vector<int> perm(n);
	for (int i = 0; i < n; ++i) perm[i] = i;

	Tree T(n);
	shuffle(perm.begin() + 1, perm.end());
	for (int i = 1; i < n; ++i)
		if (rnd.next(2))
			T.ed.push_back(std::make_pair(perm[i], perm[p[i]]));
		else
			T.ed.push_back(std::make_pair(perm[p[i]], perm[i]));
	shuffle(T.ed.begin(), T.ed.end());

	int trans = rnd.next(n);
	for (auto& [u, v] : T.ed) (u += trans) %= n, (v += trans) %= n;

	return T;
}

int main(int argc, char* argv[]) {
	registerGen(argc, argv, 1);
	int n = opt<int>("n");
	int t = opt<int>("t");

	Tree T = generate_tree(n, t);

	T.print();

	return 0;
}