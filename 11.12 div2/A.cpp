#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve(){
    ll a1,a2,a3;
    cin>>a1>>a2>>a3;
    ll t = a1+a2+a3;
    if(t%3==0) cout<<0<<endl;
    else cout<<1<<endl;
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