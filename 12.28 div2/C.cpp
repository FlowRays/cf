#include <bits/stdc++.h>

#define forn(i, n) for (ll i = 0; i < ll(n); i++)
#define fore(i, l, r) for (ll i = ll(l); i <= ll(r); ++i)
#define sz(a) ll((a).size())
#define endl "\n"
#define pii pair<ll,ll>

using namespace std;
using ll = long long;

void solve(){
    ll n;
    cin>>n;
    vector<ll> a(n);
    forn(i,n) cin>>a[i];
    auto check = [&](ll x){
        vector<ll> b(a.begin(),a.end());
        for(ll i=n-1;i>=2;--i){
            if(b[i]<x) return false;
            int t = min(b[i]-x,a[i])/3;
            b[i-1] += t;
            b[i-2] += 2*t;
        }
        if(b[0]<x || b[1]<x) return false;
        return true;
    };
    ll l = 0, r = 1e9;
    while(l<r){
        ll mid = (l+r+1ll)/2ll;
        if(check(mid)) l=mid;
        else r=mid-1ll;
        // cout<<l<<" "<<mid<<" "<<r<<endl;
    }
    cout<<l<<endl;
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