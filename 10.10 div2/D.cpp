#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve(){
    ll n;
    cin>>n;
    vector<int> a(n),b(n);
    for(int i=0;i<n;++i) cin>>a[i]>>b[i];
    map<int,ll> mp1,mp2;
    for(int i=0;i<n;++i){
        mp1[a[i]]++;
        mp2[b[i]]++;
    }
    ll ans = n*(n-1)*(n-2)/6;
    for(int i=0;i<n;++i){
        ans -= (mp1[a[i]]-1)*(mp2[b[i]]-1);
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