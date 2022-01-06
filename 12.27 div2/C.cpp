#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define fore(i, l, r) for (int i = int(l); i <= int(r); ++i)
#define sz(a) int((a).size())
#define endl "\n"
#define pii pair<int,int>

using namespace std;
using ll = long long;

void solve(){
    ll n,k;
    cin>>n>>k;
    vector<ll> a(n);
    forn(i,n) cin>>a[i];
    sort(a.begin(),a.end());
    ll m = a.front();
    vector<ll> s(n);
    forn(i,n){
        if(i==0) s[i]=a[i];
        else s[i]=s[i-1]+a[i];
    }
    ll ans = 1e18;
    forn(y,n){
        ll x = (max(0ll,s[n-y-1]+m*y-k)+y)/(y+1); // +y 用于上取整
        ans = min(ans,y+x);
        // cout<<y<<" "<<ans<<endl;
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