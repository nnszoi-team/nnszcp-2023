#include<bits/stdc++.h>
using namespace std;
struct node{
	int l1,l2,l3,l4,l5,l6,l7,q1,q2,q3,q4,q5,q6,q7,sum,zong,r;
};
node a[1006];
int n,m;
int s1,s2,s3,s4,s5,s6,s7;
bool cmp(node x,node y){
	if(x.q7!=y.q7){
		return x.q7>y.q7;
	}
	else return x.zong>y.zong;
}
int main(){
	cin>>s1>>s2>>s3>>s4>>s5>>s6>>s7;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].l1>>a[i].l2>>a[i].l3>>a[i].l4>>a[i].l5>>a[i].l6>>a[i].l7;
		a[i].sum=a[i].l1+a[i].l2+a[i].l3+a[i].l4+a[i].l5+a[i].l6+a[i].l7;
		if(a[i].sum>=s7) {
		a[i].q7=1;}
		else a[i].q7=0;
		if(a[i].l1>=s1){
		a[i].q1=6;}
		else a[i].q1=0;
		if(a[i].l2>=s2){
		a[i].q2=5;}
		else a[i].q2=0;
		if(a[i].l3>=s3){
		a[i].q3=4;}
		else a[i].q3=0;
		if(a[i].l4>=s4){
		a[i].q4=3;}
		else a[i].q4=0;
		if(a[i].l5>=s5){
		a[i].q5=2;}
		else a[i].q5=0;
		if(a[i].l6>=s6){
		a[i].q6=1;}
		else a[i].q6=0;
		a[i].zong=a[i].q1+a[i].q2+a[i].q3+a[i].q4+a[i].q5+a[i].q6;
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++){
		a[i].r=i;
	}
	for(int i=m;i<=n;i++){
		if(a[m+1].zong==a[m].zong){
			m++;
		}
		else break;
	}
	cout<<m;
	return 0;
}