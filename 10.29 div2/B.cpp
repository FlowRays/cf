#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve(){
    ll n,k;
    cin>>n>>k;
    if(n==1){
        cout<<0<<endl;
        return;
    }
    ll x = 2;
    ll ans = 1;
    ll dx[2] = {1,0};
    int t = 1;
    while(x<n){
        dx[t] = min(k,x);
        x += dx[t];
        ans++;
        if(dx[t]==dx[!t]) break;
        t = !t;
    }
    if(x>=n){
        cout<<ans<<endl;
        return;
    }
    ll d = ((n-x)%dx[0]==0 ? (n-x)/dx[0] : (n-x)/dx[0]+1);
    ans += d;
    cout<<ans<<endl;
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