#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int mod = 998244353;
int n,x;
int dp[510][510],c[510][510];

int add(int a,int b){
    return (a+b)%mod;
}

int mul(int a,int b){
    return a*1ll*b%mod;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    for(int i=0;i<=500;++i){
        c[i][0] = c[i][i] = 1;
        for(int j=1;j<i;++j){
            c[i][j] = add(c[i-1][j-1],c[i-1][j]);
        }
    }
    cin>>n>>x;
    dp[n][0] = 1;
    for(int i=n;i>=2;--i){
        for(int j=0;j<x;++j){
            if(!dp[i][j]) continue;
            int pw = 1, nj = min(x,j+i-1);
            for(int k=i;k>=0;--k){
                dp[k][nj] = add(dp[k][nj],mul(dp[i][j],mul(c[i][k],pw)));
                pw = mul(pw,nj-j);
            }
        }
    }
    int ans = 0;
    for(int i=0;i<=x;++i){
        ans = add(ans,dp[0][i]);
    }
    cout<<ans<<endl;

    return 0;
}