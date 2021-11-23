/*
画图 分类讨论
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve(){
    ll n,m,k;
    cin>>n>>m>>k;
    if(k<=1){
        cout<<"NO"<<endl;
        return;
    }
    if(n==1 && m==0){
        cout<<"YES"<<endl;
        return;
    }
    if(k==2){
        cout<<"NO"<<endl;
        return;
    }
    ll c = n*(n-1)/2;
    if(k==3){
        if(c==m) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        return;
    }
    if(m>=n-1 && m<=c) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }

    return 0;
}