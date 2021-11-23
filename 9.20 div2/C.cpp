#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll inf = 9e18;

void solve(){
    int n;
    cin>>n;
    vector<ll> a(n),b(n);
    for(int i=0;i<n;++i) cin>>a[i],b[i]=-a[i];
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    int m;
    cin>>m;
    ll x,y;
    ll s = accumulate(a.begin(),a.end(),0ll);
    for(int i=0;i<m;++i){
        cin>>x>>y;
        auto t1 = lower_bound(a.begin(),a.end(),x), t2 = lower_bound(b.begin(),b.end(),-x);
        ll ans1 = inf,ans2 = inf;
        if(t1!=a.end()) ans1 = (s-*t1-y>=0 ? 0 : *t1+y-s);
        if(t2!=b.end()) ans2 = x+*t2+(s+*t2-y>=0 ? 0 : -*t2+y-s);
        cout<<min(ans1,ans2)<<endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    tt = 1;
    while (tt--) {
        solve();
    }

    return 0;
}