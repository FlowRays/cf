#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll mod = 1e9+7;

void solve(){
    ll n,k;
    cin>>n>>k;
    ll t = k;
    vector<int> a;
    while(t>0){
        a.push_back(t&1);
        t >>= 1;
    }
    t = 1;
    ll ans = 0;
    for(auto& x: a){
        ans += t*x;
        ans %= mod;
        t = (t*n)%mod;
    }
    cout<<ans<<endl;
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

/*
10
1 1
1 2
1 3
1 4
1 5
1 6
1 7
1 8

*/