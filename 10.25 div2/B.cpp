#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve(){
    int n;
    cin>>n;
    map<int,int> mp[2010];
    vector<int> a(n+1);
    for(int i=1;i<=n;++i) cin>>a[i],mp[1][a[i]]++;
    int cnt = 0;
    for(int i=2;i<=2000;++i){
        bool ok = false;
        for(auto [x,y]: mp[i-1]){
            if(mp[i][y]!=0) ok = true;
            mp[i][y]+=y;
        }
        if(!ok){
            cnt = i;
            break;
        }
    }
    // cout<<cnt<<endl;
    map<int,vector<int>> ans;
    for(auto [x,y]: mp[1]){
        int t = y;
        ans[x].push_back(x);
        ans[x].push_back(t);
        for(int i=2;i<=cnt;++i){
            ans[x].push_back(mp[i][t]);
            t = mp[i][t];
        }
    }
    // for(auto [x,y]:mp[1]){
    //     cout<<x<<": ";
    //     for(auto t: ans[x]){
    //         cout<<t<<" ";
    //     }
    //     cout<<endl;
    // }
    int q;
    cin>>q;
    for(int i=0,xi,k;i<q;++i){
        cin>>xi>>k;
        cout<<ans[a[xi]][k>=cnt ? cnt : k]<<endl;
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