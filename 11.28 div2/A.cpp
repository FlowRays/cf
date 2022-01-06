#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    int cnt = 0;
    for(int i=0;i<n;++i){
        cin>>a[i];
        while(a[i]%2==0){
            a[i]/=2;
            cnt++;
        }
    }
    sort(a.begin(),a.end());
    ll ans = 0;
    for(int i=0;i<n-1;++i){
        ans += a[i];
    }
    ans += a.back()*(1ll<<cnt);
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