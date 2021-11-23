#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve(){
    ll n,k;
    cin>>n>>k;
    vector<ll> a(n);
    map<ll,ll> mp;
    ll t = 1;
    for(int i=0;i<10;++i){
        mp[i] = t;
        t *= 10ll;
    }
    for(ll i=0;i<n;++i) cin>>a[i];
    bool ok = false;
    ll ans = 0;
    for(ll i=1;i<n;++i){
        ll x = mp[a[i]-a[i-1]]-1ll;
        if(k>=x){
            k -= x;
            ans += x*mp[a[i-1]];
        }
        else{
            ans += (k+1)*mp[a[i-1]];
            ok = true;
            break;
        }
    }
    if(!ok){
        ans += (k+1)*mp[a[n-1]];
    }
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