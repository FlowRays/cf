#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll mod = 998244353;

map<ll,ll> mp;

ll p(ll a,ll b){
    ll res = 1;
    while(b>0){
        if(b&1) res = res*a%mod;
        a = a*a%mod;
        b>>=1;
    }
    return res;
}

void solve(){
    ll n,x;
    cin>>n>>x;
    ll ans = p(x,n);
    for(ll i=n-1;i<x;++i){  
        if((i+1)%n==0 && (i+1)/n!=1) continue; 
        ans -= (p(i,n-1)*n)%mod;
        ans = (ans+mod)%mod;
    }

    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    tt = 1;
    mp[0] = 1;
    for(ll i=1;i<=550;++i){
        mp[i] = mp[i-1]*i%mod;
    }
    while (tt--) {
        solve();
    }

    return 0;
}