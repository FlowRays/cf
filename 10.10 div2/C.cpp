#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve(){
    int n;
    cin>>n;
    vector<ll> a(n);
    ll s = 0;
    map<ll,ll> mp;
    for(auto& x: a){
        cin>>x;
        s += x;
        mp[x]++;
    }
    // for(auto x: a) cout<<x<<" ";
    // cout<<endl;
    if(2*s%n!=0){
        cout<<0<<endl;
        return;
    }
    ll t = 2*s/n;
    ll ans = 0;
    // cout<<t<<endl;
    for(ll i=0;i<n;++i){
        // cout<<t-a[i]<<endl;
        ans += mp[t-a[i]];
        if(t-a[i]==a[i]) ans--;
    }
    cout<<ans/2<<endl;
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