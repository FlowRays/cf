#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 4e5+10;
const int inf = 0x3f3f3f3f;
vector<int> e[N];

void solve(){
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;++i) e[i].clear();
    for(int i=0,u,v;i<n-1;++i){
        cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    vector<int> a(n+1);
    vector<int> vis(n+1,0);
    vector<int> cnt(n+1);
    queue<int> q;
    for(int i=1;i<=n;++i){
        if(e[i].size()<=1){
            q.push(i);
            a[i] = 1;
            vis[i] = 1;
        }
        cnt[i] = e[i].size();
    }
    while(q.size()){
        int x = q.front();
        q.pop();
        for(auto y: e[x]){
            cnt[y]--;
            if(!vis[y] && cnt[y]<=1){
                a[y] = a[x]+1;
                vis[y] = 1;
                q.push(y);
            }
        }
    }
    int ans = 0;
    for(int i=1;i<=n;++i){
        if(a[i]>k) ans++;
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
1

7 1
7 1
1 2
2 3
2 4
2 5
5 6
*/