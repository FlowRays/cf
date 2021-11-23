#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve(){
    int n,m;
    cin>>n>>m;
    vector<int> vis(n+1,0);
    for(int i=0,a,b,c;i<m;++i){
        cin>>a>>b>>c;
        vis[b] = 1;
    }
    int t = -1;
    for(int i=1;i<=n;++i){
        if(vis[i]==0){
            t = i;
            break;
        }
    }
    for(int i=1;i<=n;++i){
        if(i!=t){
            cout<<t<<" "<<i<<endl;
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