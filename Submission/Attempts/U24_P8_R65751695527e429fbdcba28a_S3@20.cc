#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,s=0;
	cin>>n;
	int a[200000];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(a[i]<a[j]){
				swap(a[i],a[j]);
				s++;
			}
		}
	}
	for(int i=0;i<n-1;i++){
		if(a[i]>a[i+1]){
			cout<<"NO";
			return 0;
		}
	}
	cout<<"YES"<<endl<<s;
	return 0;
}