#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve(){
    int n;
    cin>>n;
    vector<vector<int>> e(n+1);
    vector<int> ind(n+1,0);
    map<int,int> vis;
    for(int i=0,k;i<n;++i){
        cin>>k;
        int u = i+1;
        for(int j=0,v;j<k;++j){
            cin>>v;
            e[v].push_back(u);
            ind[u]++;
        }
    }
    int ans = 0;
    priority_queue<int,vector<int>,greater<int>> q[2];
    for(int i=1;i<=n;++i){
        vis[i] = 0;
        if(ind[i]==0) q[0].push(i);
    }
    int t = 0;
    while(true){
        ans++;
        int cnt = 0;
        while(q[t].size()){
            int x = q[t].top();
            vis.erase(x); // xx
            q[t].pop();
            for(auto y: e[x]){
                ind[y]--;
                if(ind[y]==0){
                    cnt++;
                    if(y>x) q[t].push(y);
                    else q[!t].push(y);
                }
            }
        }
        if(vis.size()==0) break;
        t = !t;
        if(cnt==0){
            cout<<-1<<endl;
            return;
        }
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