#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve(){
    ll n,l,r,k;
    cin>>n>>l>>r>>k;
    vector<ll> a(n),b;
    for(auto& x: a){
        cin>>x;
        if(x>=l && x<=r) b.push_back(x);
    }
    sort(b.begin(),b.end());
    ll s = 0;
    ll ans = 0;
    for(int i=0;i<b.size();++i){
        if(s+b[i]>k){
            break;
        }
        s += b[i];
        ans++;
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