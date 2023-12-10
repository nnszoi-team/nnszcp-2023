#include<bits/stdc++.h>
using namespace std;
const long long N = 1e7+5;
long long s[N];
int main()
{
	long long m, n;
	int t, sum, cnt;
	cin >> t;
	for(int i = 0; i <= t; i++){
		cin >> s[i];
	}
	
	m = s[0];
	for(int i = 0; i <= t; i++){
		if(s[i] > s[0]){
			m = s[i];
		}
	}
	
	for(int i = 1; i < t; i++){
		sum = s[i+1] - s[i];
		cnt = s[i] - s[i-1];
		if(sum > cnt){
		n = cnt;
		//cout << n << " ";
		}
		else{
			n = sum;
			//cout << n << " ";
		}
	}
	cout << m << endl << n;
	return 0;
}