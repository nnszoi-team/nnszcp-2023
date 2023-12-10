#include<bits/stdc++.h>
using namespace std;
int main() {
    int n,sum=0;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (a[i] < a[j]) {
                swap(a[i], a[j]);
                sum++;
            }
        }
    }
	cout<<"YES"<<endl<<sum;
    return 0;
}