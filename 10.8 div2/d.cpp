#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 2e5+10;
int f[N];

int find(int x){
    if(x==f[x]) return x;
    return f[x]=find(f[x]);
}

void solve(){
    int n,m;
    cin>>n>>m;
    string c;
    vector<int> mp(n+1,0);
    bool ok = true;
    for(int i=1;i<=n;++i) f[i] = i;
    vector<tuple<int,int,int>> vm(m);
    for(int i=0,a,b;i<m;++i){
        cin>>a>>b>>c;
        int t = (c[0]=='i' ? -1 : 1);
        vm[i] = make_tuple(min(a,b),max(a,b),t);
        f[find(a)] = find(b);                    
    }
    sort(vm.begin(),vm.end());
    for(auto [a,b,t]: vm){
        // int a = vm[i].
        if(ok){
            if(mp[a]==0 && mp[b]==0){
                mp[a] = 1;
                mp[b] = (t==1 ? 1 : -1);
            }
            else if(mp[a]==0 && mp[b]==-1){
                mp[a] = (t==1 ? -1 : 1);
            }
            else if(mp[a]==0 && mp[b]==1){
                mp[a] = (t==1 ? 1 : -1);
            }
            else if(mp[a]==-1 && mp[b]==-1){
                if(t==-1) ok = false;
            }
            else if(mp[a]==-1 && mp[b]==0){
                mp[b] = (t==1 ? -1 : 1);
            }
            else if(mp[a]==-1 && mp[b]==1){
                if(t==1) ok = false;
            }
            else if(mp[a]==1 && mp[b]==-1){
                if(t==1) ok = false;
            }
            else if(mp[a]==1 && mp[b]==0){
                mp[b] = (t==1 ? 1 : -1);
            }
            else if(mp[a]==1 && mp[b]==1){
                if(t==-1) ok = false;
            }
        }
    }
    if(!ok) cout<<-1<<endl;
    else{
        map<int,pair<int,int>> cnt;
        for(int i=1;i<=n;++i){
            int fa = find(i);
            auto [x,y] = cnt[fa];
            x += (mp[i]==1 ? 1 : 0);
            y++;
            cnt[fa] = make_pair(x,y);
        }
        ll ans = 0;
        ll tot = 0;
        for(auto [x,y]: cnt){
            tot += y.second;
            ans += max(y.first,y.second-y.first);
        }
        ans += (n-tot);
        cout<<ans<<endl;
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