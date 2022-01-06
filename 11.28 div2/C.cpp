#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 2e5+10;
const int M = 1e6+10;
int dp[N][3];
int yc[N][3];
int p[M];

void solve(){
    int n,e;
    cin>>n>>e;
    vector<int> a(n+1);
    for(int i=1;i<=n;++i){
        cin>>a[i];
        dp[i][0] = dp[i][1] = dp[i][2] = 0;
        yc[i][0] = yc[i][1] = yc[i][2] = 0;
    }
    for(int i=1;i<=e;++i){
        // 2为1，0为质数，1为合数
        dp[i][p[a[i]]] = 1;
        dp[i][0] = 0;
        yc[i][p[a[i]]] = 1;
    }
    for(int i=e+1;i<=n;++i){
        if(p[a[i]]==0){
            dp[i][0] = dp[i-e][2];
            yc[i][0] = 1;
        }
        else if(p[a[i]]==2){
            dp[i][0] = dp[i-e][0]+yc[i-e][0];
            dp[i][2] = dp[i-e][2]+1;
        }
    }
    ll ans = 0;
    for(int i=e+1;i<=n;++i){
        // cout<<i<<" "<<dp[i][0]<<" "<<dp[i][2]<<endl;
        ans += dp[i][0];
    }
    cout<<ans<<endl;
    // cout<<" "<<dp[n][0]<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    p[1] = 2;
    for(int i=2;i<M;++i){
        if(!p[i]){
            for(int j=i+i;j<M;j+=i){
                p[j] = 1;
            }
        }
    }
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }

    return 0;
}