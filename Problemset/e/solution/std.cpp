#include <bits/stdc++.h>
using namespace std;
int T,n,k;
int a[505][505];

void solve(){
    cin>>n>>k;
    int s=(n-1)*n*(n+1)>>1;

    if(k<s){
        cout<<-1<<endl;
        return;
    }


    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            a[i][j]=(i-1)*n+j-1+(i==n?(k-s):0);
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<a[i][j]<<' ';
        }
        cout<<endl;
    }
}

int main(){
    ios::sync_with_stdio(0);

    cin>>T;

    while(T--){
        solve();
    }


    return 0;
}