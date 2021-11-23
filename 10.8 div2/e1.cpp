#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll mod = 1e9+7;

ll qpow(ll a,ll b){
    ll res = 1;
    while(b>0){
        if(b&1) res = (res*a)%mod;
        a = (a*a) % mod;
        b >>= 1;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll k;
    cin>>k;
    // cout<<(1<<k)<<endl;
    ll ans = 6*qpow(4,(1ll<<k)-2)%mod;
    cout<<ans<<endl;



    return 0;
}