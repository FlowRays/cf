#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define fore(i, l, r) for (int i = int(l); i <= int(r); ++i)
#define sz(a) int((a).size())
#define endl "\n"
#define pii pair<int,int>

using namespace std;
using ll = long long;

void solve(){
    ll n;
    cin>>n;
    vector<ll> a(n);
    forn(i,n) cin>>a[i];
    ll t1 = a[0], t2 = a[1];
    for(ll i=2;i<n;i+=2) t1 = gcd(t1,a[i]);    
    for(ll i=3;i<n;i+=2) t2 = gcd(t2,a[i]);
    if(t1==t2) cout<<0<<endl;
    else{
        bool ok = false;
        for(ll i=0;i<n;i+=2){
            if(a[i]%t2==0){
                ok = true;
                break;
            }
        }
        if(!ok) cout<<t2<<endl;
        else{
            ok = false;
            for(ll i=1;i<n;i+=2){
                if(a[i]%t1==0){
                    ok = true;
                    break;
                }
            }
            cout<<(ok ? 0 : t1)<<endl;
        }
    }
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