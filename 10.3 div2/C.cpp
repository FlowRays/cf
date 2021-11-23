// 非常有意思的一题，树上异或，完全按照editorial实现
// https://codeforces.com/blog/entry/95583

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 1e5+10;
int a[N],b[N];
int s;
vector<int> e[N];
int cnt;
bool found;

void dfs(int u,int fa){
    b[u] = a[u];
    for(auto& x: e[u]){
        if(x == fa) continue;
        dfs(x,u);
        if(found) return;
        b[u] ^= b[x];
    }
    if(b[u]==s && fa!=-1){
        cnt++;
        found = true;
        for(auto it = e[u].begin(); it != e[u].end(); ++it){
            if(*it == fa){
                e[u].erase(it);
                break;
            }
        }
        for(auto it = e[fa].begin(); it != e[fa].end(); ++it){
            if(*it == u){
                e[fa].erase(it);
                break;
            }
        }
    }
}

void solve(){
    int n,k;
    cin>>n>>k;
    s = 0;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        s ^= a[i];
        e[i].clear();
    }
    for(int i=1,u,v;i<n;++i){
        cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    if(s==0) cout<<"YES"<<endl;
    else{
        if(k==2) cout<<"NO"<<endl;
        else{
            cnt = 0; found = false;
            dfs(1,-1);
            found = false;
            dfs(1,-1);
            if(cnt==2){
                cout<<"YES"<<endl;
            }
            else cout<<"NO"<<endl;
        }
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