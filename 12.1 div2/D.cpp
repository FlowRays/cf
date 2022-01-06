#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int mod = 998244353;

int add(int x,int y){
    return (x%mod+y%mod)%mod;
}

// int add(int x, int y) {
//     x += y;
//     if (x >= mod) x -= mod;
//     return x;
// }

void solve(){
    int n;
    cin>>n;
    vector<int> dp1(n+2),dp2(n+2);
    dp1[0] = 1; // 初始状态 空序列满足i=0,mex=0的情况
    for(int i=1,x;i<=n;++i){
        cin>>x;
        dp1[x+1] = add(dp1[x+1],dp1[x+1]); // 相当于*2，一个是i-1状态下的值，另一个是i状态下由i-1转移过来的值
        dp1[x+1] = add(dp1[x+1],dp1[x]);
        if(x>0){
            dp2[x-1] = add(dp2[x-1],dp2[x-1]); // 顺序不能错 因为并不是完全的加，而是先*2再+
            dp2[x-1] = add(dp2[x-1],dp1[x-1]);
        }
        dp2[x+1] = add(dp2[x+1],dp2[x+1]);
    } 
    int ans = 0;
    for(auto x: dp1) ans = add(ans,x);
    for(auto x: dp2) ans = add(ans,x);
    cout<<(ans-1 + mod)%mod<<endl; // 减去空序列的情况 不能直接-1，因为经过上面的运算取模后可能得到0
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