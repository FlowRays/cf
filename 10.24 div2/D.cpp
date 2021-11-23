#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve(){
    ll n;
    cin>>n;
    vector<ll> a(n),b(n),ans(n);
    vector<pair<ll,ll>> v(n);
    for(ll i=0;i<n;++i){
        cin>>a[i];
        v[i] = make_pair(abs(a[i]),i);
    }
    sort(v.begin(),v.end());
    if(a.size()%2==1){
        ll p = v[0].second, q = v[1].second, r = v[2].second;
        ll x = a[p], y = a[q], z = a[r];
        /*
3
-1 1 -1
        */
        if(x!=y && y!=z && x!=z){
            b[0] = y-z;
            b[1] = z-x;
            b[2] = x-y;
            ans[p] = b[0];
            ans[q] = b[1];
            ans[r] = b[2];
        }
        else{
            if(x==y){
                ans[p] = z;
                ans[q] = z;
                ans[r] = -2*x;                
            }
            else if(y==z){
                ans[q] = x;
                ans[r] = x;
                ans[p] = -2*y;                  
            }
            else{
                ans[p] = y;
                ans[r] = y;
                ans[q] = -2*x;                 
            }
        }
        for(int i=3;i<n;i+=2){
            x = v[i].first, y = v[i+1].first;
            p = v[i].second, q = v[i+1].second;
            ans[p] = (a[p]<0 ? y : -y);
            ans[q] = (a[q]<0 ? -x : x);
        }
    }
    else{
        for(int i=0;i<n;i+=2){
            ll x = v[i].first, y = v[i+1].first;
            ll p = v[i].second, q = v[i+1].second;
            ll g = gcd(x,y);
            ll m = x*y/g;
            ll t1 = m/x, t2 = m/y;
            ans[p] = (a[p]<0 ? t1 : -t1);
            ans[q] = (a[q]<0 ? -t2 : t2);
        }
    }
    for(int i=0;i<n;++i){
        cout<<ans[i]<<(i==n-1 ? '\n' : ' ');
    }
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