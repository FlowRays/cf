#include <bits/stdc++.h>

#define forn(i, n) for (ll i = 0; i < ll(n); i++)
#define fore(i, l, r) for (ll i = ll(l); i <= ll(r); ++i)
#define sz(a) ll((a).size())
#define endl "\n"
#define pii pair<ll,ll>

using namespace std;
typedef long long ll;

const ll mod = 998244353;

ll inv(ll x){
    ll res = 1;
    ll p = mod-2;
    while(p){
        if(p&1) res = (res*1ll*x)%mod;
        x = (x*1ll*x)%mod;
        p>>=1;
    }
    return res;
}

ll fac[5010],invf[5010];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    vector<ll> pref(n+1,0);
    fac[0] = invf[0] = 1;
    fore(i,1,5001) fac[i] = (fac[i-1]*i)%mod;
    fore(i,1,5001) invf[i] = inv(fac[i])%mod;
    forn(i,n) pref[i+1] = pref[i]+s[i]-'0';
    ll ans = 0;
    if(pref[n]>=k){
        forn(i,n){
            fore(j,i+1,n-1){
                ll x = pref[j+1]-pref[i];
                if(x<=k){
                    ll len = j-i+1-2;
                    if(s[i]=='0') x--;
                    if(s[j]=='0') x--;
                    if(x>=0) ans = (ans+fac[len]*invf[x]%mod*invf[len-x]%mod)%mod;
                }
            }
        }
    }
    cout<<(ans+1)%mod<<endl;

    return 0;
}