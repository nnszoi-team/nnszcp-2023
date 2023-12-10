#include<bits/stdc++.h>
using namespace std;
int main(){
	long long a,b,x=-100000000,c,s,y,z,u,n;
	cin>>n;
	for(int i=0;i<=n;i++){
	cin>>a;
	b=a;
	if(b>=x)s=b;
	if(i>=2){
	if(b>x)c=b-x;
	else c=x-b;
	y=c;
	if(y>=z)u=y;
	z=y;
	}
	x=b;
	}
	cout<<s<<endl<<u;	
	return 0;
}