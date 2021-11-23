#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve(){
    int n;
    cin>>n;
    vector<int> a(n),b(n),c(n);
    vector<pair<int,int>> v;
    for(int i=0;i<n;++i) cin>>a[i],v.emplace_back(a[i],i);
    for(int i=0;i<n;++i) cin>>b[i];
    sort(v.begin(),v.end());
    int ans = 1e9;
    for(int i=0,j=0;i<n;++i){
        int x = a[v[i].second];
        while(x>b[j]) j++;
        c[i] = j;
        int p1 = v[i].second, p2 = j;
        ans = min(ans,p1+p2);
        // cout<<c[i]<<" ";
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