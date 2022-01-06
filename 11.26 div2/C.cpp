#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll mod = 1e9+7;
const ll N = 2e5+10;
ll fac[N],inv[N];

ll qpow(ll a,ll b){
    ll res = 1;
    while(b){
        if(b&1) res = (res*a)%mod;
        a = (a*a)%mod;
        b>>=1;
    }
    return res;
}

// void init(){
//     fac[0] = 1;
//     for(ll i=1;i<N;++i){
//         fac[i] = fac[i-1]*i%mod;
//     }
//     inv[N-1] = qpow(fac[N-1],mod-2);
//     for(ll i=N-2;i>=0;i--){
//         inv[i] = (inv[i+1]*(i+1))%mod;
//     }
// }

ll C(ll n,ll m){
    if(m<0 || m>n) return 0;
    return fac[n]*inv[m]%mod*inv[n-m]%mod;
}

void solve(){
    ll n,m;
    cin>>n>>m;
    vector<ll> cnt(33);
    // vector<tuple<ll,ll,ll,ll>> p;
    // vector<ll> a(n+1,-1);
    for(ll i=0,a,b,c;i<m;++i){
        cin>>a>>b>>c;
        ll ws = 0;
        while(c){
            cnt[ws++] += c%2;   
            c>>=1;
        }
        // p.emplace_back(b-a,a,b,c);
    }
    // sort(p.begin(),p.end());
    // for(auto [dis,l,r,x]: p){
        // for(ll i=l;i<=r;i+=2){
        //     if(a[i]==-1){
        //         a[i] = x;
                // ll ws = 0;
                // while(x){
                //     cnt[ws++] += x%2;   
                //     x>>=1;
                // }
                // break;
            // }
        // }
    // }
    // cout<<"a: ";
    // for(ll i=1;i<=n;++i){
        // cout<<a[i]<<" ";
    // }
    // cout<<endl;
    ll ans = 0;
    ll qz = 1;

    for(ll i=0;i<cnt.size();++i){
        if(cnt[i]!=0){
            // cout<<" "<<cnt[i]<<" ";
            // ll c = 0;
            // for(ll j=1;j<=cnt[i];j+=2){
            //     for(ll t=j;t<=n-cnt[i]+j;++t){
            //         c = (c+C(cnt[i],j)*C(n-cnt[i],t-j)%mod)%mod;
            //     }
            // }
            ll c = qpow(2,n-1);
            ans = (ans+c*qz%mod)%mod;
            // cout<<" "<<i<<" "<<cnt[i]<<" "<<c<<endl;
        }
        qz *= 2ll;
    }
    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // init();
    // cout<<fac[5]<<" "<<inv[2]<<" "<<inv[3]<<endl;
    // cout<<C(5,2)<<endl;
    ll tt;
    cin>>tt;
    while (tt--) {
        solve();
    }

    return 0;
}