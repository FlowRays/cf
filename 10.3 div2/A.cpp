#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve(){
    int n,h;
    cin>>n>>h;
    vector<int> a(n);
    for(int i=0;i<n;++i) cin>>a[i];
    sort(a.begin(),a.end(),greater<int>());
    ll ans = h/(a[0]+a[1])*2;
    h = h%(a[0]+a[1]);
    if(h>0 && h<=a[0]) ans++;
    else if(h>a[0]) ans+=2;
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