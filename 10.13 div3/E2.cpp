#include <bits/stdc++.h>

using namespace std;
using ll = long long;


void solve(){
    int n,k;
    cin>>n>>k;
    vector<vector<int>> e(n+1);
    vector<int> d(n+1),vis(n+1,0),ans(n+1,0);
    for(int i=0,u,v;i<n-1;++i){
        cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    queue<int> q;
    for(int i=1;i<=n;++i){
        d[i] = e[i].size();
        if(d[i]<=1){
            q.push(i);
            ans[i] = 1;
            vis[i] = 1;
        }
    }
    while(q.size()){
        int x = q.front();
        q.pop();
        for(auto y: e[x]){
            d[y]--;
            if(!vis[y] && d[y]<=1){
                vis[y] = 1;
                ans[y] = ans[x]+1;
                q.push(y);
            }
        }
    }
    int cnt = 0;
    for(int i=1;i<=n;++i){
        if(ans[i]>k) cnt++;
    }
    cout<<cnt<<endl;
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