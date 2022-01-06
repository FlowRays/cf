#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define fore(i, l, r) for (int i = int(l); i <= int(r); ++i)
#define sz(a) int((a).size())
#define endl "\n"
#define pii pair<int,int>

using namespace std;
using ll = long long;

vector<vector<int>> e;
vector<int> ans;

void dfs(int x){
    for(auto v: e[x]){
        if(!ans[v]){
            ans[v] = 1;
            dfs(v);
        }
    }
}

void solve(){
    int n;
    cin>>n;
    vector<pii> a,b;
    forn(i,n){
        int x;
        cin>>x;
        a.emplace_back(x,i);
    }
    forn(i,n){
        int x;
        cin>>x;
        b.emplace_back(x,i);
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    e.clear();
    e.resize(n);
    ans.assign(n,0); // 不能用resize
    fore(i,1,n-1){
        int u = a[i].second, v = a[i-1].second;
        e[v].push_back(u); // 反向建边
    }
    fore(i,1,n-1){
        int u = b[i].second, v = b[i-1].second;
        e[v].push_back(u);
    }
    int am = a.back().second;
    ans[am] = 1;
    dfs(am);
    forn(i,n) cout<<ans[i];
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