#include<bits/stdc++.h>
using namespace std;
int main(){
	char a[110];
	cin.getline(a,110);
	int s=strlen(a);
	for(int i=0;i<s;i++){
		if(a[i]=='n'){
			if(a[i+1]=='n'&&a[i+2]=='s'&&a[i+3]=='z'){
				cout<<"YES";
				return 0;
			}
		}
	}
	cout<<"NO";
	return 0;
}