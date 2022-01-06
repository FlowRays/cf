#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};


void solve(){
    int n,m;
    cin>>n>>m;
    vector<string> mp(n);
    for(int i=0;i<n;++i) cin>>mp[i];
    queue<pair<int,int>> q;
    vector<vector<int>> vis(n,vector<int>(m,0));
    vector<vector<int>> deg(n,vector<int>(m,4));
    auto che = [&](int x,int y){
        if(x>=0 && x<n && y>=0 && y<=m && mp[x][y]=='.') return true;
        return false;
    };
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if(mp[i][j]=='L'){
                q.push(make_pair(i,j));
                vis[i][j] = 0;
            }
            for(int k=0;k<4;++k){
                int nx = i+dx[k], ny = j+dy[k];
                if(!che(nx,ny)) deg[i][j]--;
            }
        }
    }
    auto check = [&](int x,int y){
        if(x>=0 && x<n && y>=0 && y<=m && vis[x][y]==0 && mp[x][y]=='.' && deg[x][y]<=1) return true;
        return false;
    };
    while(q.size()){
        int x = q.front().first, y = q.front().second;
        q.pop();
        for(int i=0;i<4;++i){
            int nx = x+dx[i], ny = y+dy[i];
            if(che(nx,ny)){
                if(mp[x][y]!='L') deg[nx][ny]--;
                if(check(nx,ny)){
                    q.push(make_pair(nx,ny));
                    vis[nx][ny] = 1;
                }
            }
        }
    }
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if(mp[i][j]=='L') cout<<"L";
            else cout<<(vis[i][j]==1 ? '+' : mp[i][j]);
        }
        cout<<"\n";
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