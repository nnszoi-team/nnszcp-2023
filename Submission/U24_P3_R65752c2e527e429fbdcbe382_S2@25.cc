#include<iostream>
using namespace std;
int main(){
	int n,s=0,d=0;
	cin>>n;
	int a[n+5];
	for(int i=1;i<=n+1;i++){
		cin>>a[i];
		s=max(s,a[i]);
	}
	cout<<s<<endl;
	for(int i=1;i<=n;i++){
		d=max(d,a[i+1]-a[i]);
	}
	cout<<d;
}