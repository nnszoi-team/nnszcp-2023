#include <bits/stdc++.h> 
using namespace std;
long long n; 
int main()
{
	cin>>n;
	long long a[n],b[n];
	double k[n],x[n],y[n];
	double hyy[n];
	for (int i=0;i<n;i++)
	{
		cin>>a[i]>>b[i];
		k[i]=a[i]/b[i];
		x[i]=-1.00*k[i]/2.00;
		y[i]=x[i]*(k[i]-x[i])*1.00;
		hyy[i]=y[i]*y[i]+x[i]*x[i]+x[i]*x[i]+1.00;  
	}
	for (int i=0;i<n;i++)
	{
		cout<<hyy[i]<<endl; 
	} 
}