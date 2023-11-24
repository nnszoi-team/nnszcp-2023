#include <bits/stdc++.h>

const int maxn = 3e5 + 9;
using namespace std;

int n, a[maxn], maxx = -2e9, maxx2 = -2e9;

int main() {
	cin >> n;
	for (int i = 1; i <= n + 1; ++i)
		cin >> a[i], maxx = max(maxx, a[i]);

	for (int i = 2; i <= n + 1; ++i) {
		maxx2 = max(maxx2, a[i] - a[i - 1]);
	}

	cout << maxx << '\n' << maxx2;
}
