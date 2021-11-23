/*
    To search on the 2 edges, We will first root the tree on node 1, 
    then we will search on the deepest subtree such that xor value of subtree equals x, 
    then erase the edge and search again for the 2nd edge.
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll N = 1e5+10;
ll a[N];
vector<ll> e[N];
ll f[N];
ll cnt;
ll s;
bool found;

void dfs(ll cur,ll fa){
    f[cur] = a[cur];
    for(auto x: e[cur]){
        if(x != fa){
            dfs(x,cur);
            if(found) return;
            f[cur] ^= f[x];
        }
    }
    if(cur!=1 && f[cur]==s){
        found = true;
        cnt++;
        // cout<<"cnt:"<<cnt<<endl;
        for(auto it = e[fa].begin(); it != e[fa].end(); ++it){
            if(*it == cur){
                e[fa].erase(it);
                break;
            }
        }
        for(auto it = e[cur].begin(); it != e[cur].end(); ++it){
            if(*it == fa){
                e[cur].erase(it);
                break;
            }
        }
    }
}

void solve(){
    ll n,k;
    cin>>n>>k;
    cnt = 0;
    s = 0;
    for(ll i=1;i<=n;++i) cin>>a[i],e[i].clear(),s^=a[i];
    for(ll i=1,u,v;i<n;++i){
        cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    if(s==0){
        cout<<"YES"<<endl;
        return;
    }
    if(k==2){
        cout<<"NO"<<endl;
        return;
    }
    // for(ll i=1;i<=n;++i) cout<<f[i]<<(i==n ? '\n' : ' ');
    found = false;
    dfs(1,-1);
    found = false;
    dfs(1,-1);
    if(cnt==2) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll tt;
    cin >> tt;
    while (tt--) {
        solve();
    }

    return 0;
}