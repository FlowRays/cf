#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve(){
    ll n;
    cin>>n;
    vector<ll> a(n),b(n);
    for(ll i=0;i<n;++i) cin>>a[i];
    sort(a.begin(),a.end());
    ll ans = a[0];
    ll t = 0;
    for(ll i=0;i<n;++i){
        ans = max(ans,a[i]-t);
        t += a[i]-t;
    }
    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll tt;
    cin >> tt;
    while (tt--) {
        solve();
    }

    return 0;
}