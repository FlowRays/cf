/*
费马小定理：
    a/b mod p == (a mod p) * (b对p的乘法逆元) mod p
    b mod p的乘法逆元x满足 bx === 1 (mod p)
    由费马小定理: b^(p-1) === 1 (mod p) (要求p为素数)
    所以: bx === b^(p-1) (mod p)
    所以: x === b^(p-2) (mod p) 
    此时x可以用快速幂求解
快速幂
数学/感觉/猜测
乘法逆元的板子：
int inv(int a) {
    return a == 1 ? 1 : (long long)(p - p / a) * inv(p % a) % p;  
}
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 2e5+10;
const ll mod = 1e9+7;
ll f[N];
ll xmod;

ll ksm(ll x,ll b){
    ll res = 1;
    while(b>0){
        if(b&1) res = res*x%mod; 
        x=x*x%mod;
        b>>=1;
    }
    return res;
}

void solve(){
    int n;
    cin>>n;
    ll ans = f[2*n]*xmod%mod;
    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll x = 1;
    xmod = ksm(2,mod-2);
    for(ll i=1;i<N;++i){
        x = x*i%mod;
        f[i] = x;
    }
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }

    return 0;
}