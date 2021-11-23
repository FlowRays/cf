#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve(){
    int n,k;
    cin>>n>>k;
    vector<int> a(k);
    for(int i=0;i<k;++i) cin>>a[i];
    sort(a.begin(),a.end());
    int s = 0;
    int ans = 0;
    for(int i=k-1;i>=0;--i){
        s += n-a[i];
        if(s<n) ans++;
        else break;
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