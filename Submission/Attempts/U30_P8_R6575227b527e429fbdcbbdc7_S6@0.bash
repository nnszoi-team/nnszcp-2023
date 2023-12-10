#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int a[N];
int main() {
	int n;
	cin >> n;
	int f = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (i > 1 && a[i] > a[i-1]) {
			f = 1;
		}
	}
	if (f == 1) {
		cout << "NO";
	} else {
		cout << "YES\n" << n * (n - 1) / 2;
	}
	
	return 0;
}