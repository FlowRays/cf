#include <bits/stdc++.h>

using namespace std;
using ll = long long;

// ll f(vector<ll>& t){
//     ll beg = -1;
//     for(ll i=0;i<t.size();++i){
//         if(t[i]==0){
//             beg = i;
//             break;
//         }
//     }
//     if(beg==-1) return -1;
//     ll res = 0;
//     ll i = beg;
//     while(true){
//         while(t[(i+1)%t.size()]==0 && (i+1)%t.size()!=beg) i = (i+1)%t.size();
//         i = (i+1)%t.size();
//         if(i==beg) break;
//         ll cnt = 1;
//         while(t[(i+1)%t.size()]==1) i = (i+1)%t.size(), cnt++;
//         res = max(res,cnt);
//         i = (i+1)%t.size();
//         if(i==beg) break;
//     }
//     return res;
// }

// 求环t中最长的连续1数量
ll f(vector<ll>& t){
    if(count(t.begin(),t.end(),0)==0) return -1;
    int sz = t.size();
    int res = 0;
    for(int i=0,j=0;i<sz;++i){
        while(j<i || t[j%sz]==1) j++;
        res = max(res,j-i);
    }
    return res;
}

void solve(){
    ll n,d;
    cin>>n>>d;
    vector<ll> a(n);
    for(auto& x: a) cin>>x;
    ll k = gcd(n,d);
    ll ans = 0;
    for(ll i=0;i<k;++i){
        vector<ll> t(n/k);
        for(ll j=0;j<n/k;++j){
            t[j] = a[(i+j*(n-d))%n];
        }
        ll cnt = f(t);
        if(cnt==-1){
            cout<<"-1"<<endl;
            return;
        }
        ans = max(ans,cnt);
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