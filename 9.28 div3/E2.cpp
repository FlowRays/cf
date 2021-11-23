#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll N = 2e5+10;
ll n;
ll tr[N]; // beg from pos 0

// sum of [0,x)
ll sum(ll x){
    ll res = 0;
    for(ll i=x;i>0;i-=i&-i){
        res += tr[i-1];
    }
    return res;
}

// a[p] += x;
void add(ll p,ll x){
    for(ll i=p+1;i<=n;i+=i&-i){
        tr[i-1] += x;
    }
}

void solve(){
    cin>>n;
    memset(tr,0,sizeof(ll)*n);
    vector<ll> a(n);
    for(auto& x: a) cin>>x;
    vector<ll> b = a;
    sort(b.begin(),b.end());
    ll m = unique(b.begin(),b.end())-b.begin();
    ll ans = 0;
    for(ll i=0;i<n;++i){
        ll idx = lower_bound(b.begin(),b.begin()+m,a[i])-b.begin(); // first pos >=a[i]
        // cout<<a[i]<<" "<<idx<<endl;
        // cout<<sum(idx)<<" "<<sum(m)<<" "<<sum(idx+1)<<endl;
        ans += min(sum(idx),sum(m)-sum(idx+1));
        add(idx,1);
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