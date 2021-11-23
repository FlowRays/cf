#include <bits/stdc++.h>

using namespace std;
using ll = long long;

char mp[2010][2010];
int d[2010][2010];
int n,m;
int vis[2010][2010];

bool outrange(pair<int,int> p){
    if(p.first>n || p.first<1 || p.second>m || p.second<1) return true;
    return false;
}

void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;++i) cin>>mp[i]+1;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            d[i][j] = 0;
            vis[i][j] = 0;
        }
    }
    int dmax = 0;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            if(d[i][j]!=0){
                dmax = max(dmax,d[i][j]);
                continue;
            }
            pair<int,int> nxt,now = make_pair(i,j);
            vector<pair<int,int>> vp;
            while(true){
                vis[now.first][now.second] = 1;
                vp.push_back(now);
                if(mp[now.first][now.second]=='L') nxt = make_pair(now.first,now.second-1);
                else if(mp[now.first][now.second]=='R') nxt = make_pair(now.first,now.second+1);
                else if(mp[now.first][now.second]=='D') nxt = make_pair(now.first+1,now.second);
                else nxt = make_pair(now.first-1,now.second);
                if(outrange(nxt)){
                    int cnt = 0;
                    for(auto it=vp.rbegin();it!=vp.rend();it++){
                        d[it->first][it->second] = ++cnt;
                    }
                    break;
                }
                if(d[nxt.first][nxt.second]!=0){
                    int cnt = 0;
                    for(auto it=vp.rbegin();it!=vp.rend();it++){
                        d[it->first][it->second] = ++cnt+d[nxt.first][nxt.second];
                    }                    
                    break;
                }
                if(vis[nxt.first][nxt.second]){
                    int pos = -1;
                    for(int i=0;i<vp.size();++i){
                        if(vp[i] == nxt){
                            pos = i;
                            break;
                        }
                    }
                    int t = vp.size()-pos;
                    for(int i=pos;i<vp.size();++i){
                        d[vp[i].first][vp[i].second] = t;
                    }
                    for(int i=pos-1,j=t+1;i>=0;--i,++j){
                        d[vp[i].first][vp[i].second] = j;
                    }
                    break;
                }
                now = nxt;
            }
            dmax = max(dmax,d[i][j]);
        }
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            if(d[i][j]==dmax){
                cout<<i<<" "<<j<<" "<<dmax<<endl;
                return;
            }
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