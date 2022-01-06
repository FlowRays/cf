#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve(){
    ll n,h;
    cin>>n>>h;
    vector<ll> a(n+1);
    for(int i=1;i<=n;++i) cin>>a[i];
    ll l = 1, r = 1e18+10;
    auto check = [&] (ll x) {
        ll tot = x;
        for(int i=2;i<=n;++i){
            if(a[i]-a[i-1]<x) tot += a[i]-a[i-1];
            else tot += x;
        }
        return tot>=h;
    };
    while(l<r){
        ll mid = (l+r)>>1;
        if(check(mid)) r=mid;
        else l=mid+1;
    }
    cout<<l<<endl;
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