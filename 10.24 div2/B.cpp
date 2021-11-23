#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    map<int,ll> mp;
    for(int i=0;i<n;++i) cin>>a[i],mp[a[i]]++;
    cout<<mp[1]*(1ll<<mp[0])<<endl;
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