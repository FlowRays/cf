#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve(){
    ll n,m;
    cin>>n>>m;
    ll t1 = n/3;
    ll t2 = m/3;
    ll ans = t1*t2*3+t1*(m%3)+t2*(n%3);
    if(n%3!=0 && m%3!=0) ans += ((n%3)*(m%3)<=2 ? 1 : 2);
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