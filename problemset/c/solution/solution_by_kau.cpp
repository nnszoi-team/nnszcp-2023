#include <bits/stdc++.h>

const int maxn = 3009;
using namespace std;

int n, m, h[maxn];
vector<int> ht;

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> h[i];
		for (int j = 1; j < i; ++j) {
			ht.push_back(abs(h[i] - h[j]));
		}
	}

	sort(ht.begin(), ht.end());

	while (m--) {
		int tmp;
		cin >> tmp;

		cout << upper_bound(ht.begin(), ht.end(), tmp) - ht.begin() << '\n';
	}
}