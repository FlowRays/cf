#include <bits/stdc++.h>

#define forn(i, n) for (ll i = 0; i < ll(n); i++)
#define fore(i, l, r) for (ll i = ll(l); i <= ll(r); ++i)
#define sz(a) ll((a).size())
#define endl "\n"

using namespace std;
using ll = long long;

void solve(){
    ll n,k;
    cin>>n>>k;
    vector<ll> v1,v2;
    forn(i,n){
        ll x;
        cin>>x;
        if(x<0) v1.push_back(x);
        else v2.push_back(x);
    }
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end(),greater<ll>());
    ll ans = 0;
    ll l = 0, r = 0;
    for(ll i=0;i<v1.size();i+=k){
        if(i==0) l = abs(v1[i]);
        else{
            ans += 2ll*abs(v1[i]);
        }
    }
    for(ll i=0;i<v2.size();i+=k){
        if(i==0) r = v2[i];
        else ans += 2ll*v2[i];
    }
    ll t = min(l*2+r,r*2+l);
    cout<<ans+t<<endl;
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