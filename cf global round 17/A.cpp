#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve(){
    ll n,m;
    cin>>n>>m;
    if(n==1 && m==1){
        cout<<0<<endl;
        return;
    }
    if(n==1 || m==1) cout<<1<<endl;
    else cout<<2<<endl;
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