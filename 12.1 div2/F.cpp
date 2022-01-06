/*
1.容斥原理：
    至少违反k([0,n-1])条规则的涂色方式的集合 的 并集的元素个数
    从而用容斥原理求解 多个集合的并集个数
2.违反k条规则的方案数：
    由于违反k条规则的选择中并不是任意的选C(n-1,k)种，因为不同的规则可能相互排斥，如一个结点的多个子结点中只能选一个规则违反
    考虑dp[i][j]: 前i个结点中刚好违反j条规则(选中j条边，保证每个结点的子边最多选1条)的方案数
        d[i]: i结点的子结点数(即子边数)
    dp[i][j] = dp[i-1][j]+dp[i-1][j-1]*d[i]
    边界: dp[i][0] = 1 dp[0][j] = 0 (dp[0][0] = 1)
    ans: dp[n][k]
    note: 这n个结点指的是d[i]>0的结点个数，选择方式与这n个结点的排布方式无关，故而可以用fft优化
*/

// tle&mle版本 O(n^2)

#include <bits/stdc++.h>

#define forn(i, n) for (ll i = 0; i < ll(n); i++)
#define fore(i, l, r) for (ll i = ll(l); i <= ll(r); ++i)
#define sz(a) ll((a).size())
#define endl "\n"

using namespace std;
typedef long long ll;

const ll N = 2500; // mle
const ll mod = 998244353;
vector<vector<ll>> e;
ll dp[N][N];
ll fac[N];
ll d[N];

// 求出子结点个数
void dfs(ll x,ll fa){
    for(auto y: e[x]){
        if(y!=fa){
            d[x]++;
            d[x] %= mod;
            dfs(y,x);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin>>n;
    e.resize(n+1);
    forn(i,n-1){
        ll x,y;
        cin>>x>>y;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    dfs(1,1);
    forn(i,n) dp[0][i]=0;
    forn(i,n+1) dp[i][0]=1;
    fore(i,1,n){
        fore(j,1,n-1){
            dp[i][j] = dp[i-1][j]+dp[i-1][j-1]*d[i]%mod; // n^2的dp
            dp[i][j] %= mod;
        }
    }
    // forn(i,n) cout<<dp[n][i]<<" ";
    fac[0] = 1;
    fore(i,1,n){
        fac[i] = (fac[i-1]*i)%mod;
    }
    ll ans = 0;
    forn(k,n){
        if(k%2) ans = (ans-dp[n][k]*fac[n-k]%mod+mod)%mod;
        else ans = (ans+dp[n][k]*fac[n-k]%mod)%mod;
    }
    cout<<ans<<endl;

    return 0;
}