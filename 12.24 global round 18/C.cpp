#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define fore(i, l, r) for (int i = int(l); i <= int(r); ++i)
#define sz(a) int((a).size())
#define endl "\n"
#define pii pair<int,int>
#define tii tuple<int,int,int,int>

using namespace std;
using ll = long long;

void solve(){
    int n;
    cin>>n;
    string s,t;
    cin>>s>>t;
    int a[4] = {0};
    int b[4] = {0};
    forn(i,n){
        if(s[i]=='1' && t[i]=='1') a[0]++;
        else if(s[i]=='1' && t[i]=='0') a[1]++;
        else if(s[i]=='0' && t[i]=='0') a[2]++;
        else a[3]++;
        if(t[i]=='1') b[0]++;
        else b[2]++;
    }
    queue<tii> q;
    q.emplace(a[0],a[1],a[2],a[3]);
    map<tii,int> vis;
    vis[make_tuple(a[0],a[1],a[2],a[3])] = 1;
    while(q.size()){
        auto x = q.front();
        auto [m0,m1,m2,m3] = q.front();
        q.pop();
        if(x == make_tuple(b[0],b[1],b[2],b[3])){
            cout<<vis[x]-1<<endl;
            return;
        }
        if(m0>0){
            tii t1 = make_tuple(1+m3,m2,m1,m0-1);
            if(vis[t1]==0){
                vis[t1] = vis[x]+1;
                q.push(t1);
            }
        }
        if(m1>0){
            tii t2 = make_tuple(m3,m2+1,m1-1,m0);
            if(vis[t2]==0){
                vis[t2] = vis[x]+1;
                q.push(t2);
            }
        }
    }
    cout<<-1<<endl;
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