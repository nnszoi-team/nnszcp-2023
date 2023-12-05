#include <iostream>
#include <vector>

#include "testlib.h"

std::vector<int> readAnswer(InStream &in, const int n) {
	std::vector<int> a(n);
	for (auto &i : a) i = in.readInt(-1, 1'000'000'000) % 3;
	return a;
}

int main(int argc, char *argv[]) {
	registerTestlibCmd(argc, argv);

	int n = inf.readInt(1, 500'000);
	int q = inf.readInt(0, 500'000);

	auto jans = readAnswer(ans, n);
	auto pans = readAnswer(ouf, n);

	auto jexist = [](const std::vector<int> &answer) {
		for (const auto i : answer)
			if (i != -1) return false;
		return true;
	}(jans);

	auto pexist = [](const std::vector<int> &answer) {
		for (const auto i : answer)
			if (i != -1) return false;
		return true;
	}(pans);

	quitif(*std::min_element(pans.begin(), pans.end()) == -1 &&
			   *std::max_element(pans.begin(), pans.end()) != -1,
		   _wa, "strange output format");
	quitif(jexist && pexist, _ok, "no solution");
	quitif(pexist && (!jexist), _wa,
		   "solution exists but the participant's code shows no sulution");

	std::vector<int> prefix_zero(n + 1), prefix_two(n + 1);
	for (int i = 0; i < n; ++i) {
		prefix_two[i + 1] = prefix_two[i] + (pans[i] == 2);
		prefix_zero[i + 1] = prefix_zero[i] + (pans[i] == 0);
	}

	auto mul = [&prefix_two, &prefix_zero](const int l, const int r) {
		if (prefix_zero[r] - prefix_zero[l]) return 0;
		if ((prefix_two[r] - prefix_two[l]) % 2 == 1)
			return 2;
		else
			return 1;
	};

	for (int i = 0; i < q; ++i) {
		int l, r, v, c;
		l = inf.readInt(1, n);
		r = inf.readInt(1, n);
		ouf.quitif(l > r, _fail,
				   "the %d-th constraint has an invalid range (%d, %d)", i + 1,
				   l, r);

		v = inf.readInt(0, 2);

		--l;
		c = mul(l, r);
		ouf.quitif(c != v, _wa,
				   "the %d-th constraint (%d, %d, %d) is not satisfied, but "
				   "found v = %d",
				   i + 1, l + 1, r, v, c);
	}

	ouf.quitif(
		jexist, _fail,
		"expected no solution but participant's program just presented one");

	ouf.quitf(_ok, "accepted");

	return 0;
}
