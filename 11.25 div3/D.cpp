#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve(){
    int n,rt;
    cin>>n;
    queue<int> q;
    vector<int> b(n),p(n),d(n+1);
    vector<vector<int>> e(n+1);
    int dis = 0;
    map<int,int> mp;
    for(int i=0;i<n;++i){
        cin>>b[i];
        if(i+1==b[i]){
            q.push(i+1);
            rt = b[i];
            d[rt] = 0;
        }
        else{
            e[b[i]].push_back(i+1);
        }
    }
    for(int i=0;i<n;++i){
        cin>>p[i];
        mp[p[i]] = i;
    }
    bool ok = true;
    for(int i=0;i<n;++i){
        if(mp[b[i]]>mp[i+1]){
            ok = false;
            break;
        }
    }
    if(!ok){
        cout<<-1<<endl;
        return;
    }
    // else cout<<"+++1"<<endl;
    while(q.size()){
        int x = q.front();
        q.pop();
        for(auto v: e[x]){
            q.push(v);
            d[v] = d[x]+1;
            dis = max(dis,d[v]);
        }
    }
    // for(int i=1;i<=n;++i) cout<<d[i]<<(i==n ? '\n' : ' ');
    int maxdis = 0;
    vector<int> s(n+1,0);
    vector<int> ans(n+1,0);
    for(int i=0;i<p.size();++i){
        if(p[i]==rt) ans[rt] = 0;
        else{
            int r = p[i];
            ans[r] = max(s[d[r]]+1,maxdis-s[d[r]-1]+1)+10;
            s[d[r]] = max(s[d[r]],ans[r])+10;
            maxdis = max(maxdis,ans[r]+s[d[r]-1])+10;
            // cout<<" "<<r<<" "<<ans[r]<<endl;
        }
        // cout<<">>>"<<endl;
    }
    // cout<<"<<<"<<endl;
    // cout<<" ";
    // cout<<ans[6]<<endl;
    for(int i=1;i<=n;++i) {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
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
7
1 1 2 3 4 5 6
1 2 3 4 5 6 7

1
6
4 4 4 4 1 1
4 2 1 5 6 3
*/