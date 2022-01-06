/*
    Note that there should be a negative-sum subsegment of length 2 or 3, if there is a negative-sum subsegment.
    prove:
        假设不成立，则对于任意一个长度为2或3的子段, 都有区间和>=0, 则可以推出整个区间和>=0, 矛盾
    利用这个性质
    首先考虑dp的思想, 第一个数必然可以选
    其次，对于中间某个数ai，假设前面a[1]-a[i-1]的区间都满足条件，则只要考虑a[1]-a[i],a[2]-a[i],...,a[i-1]-a[i]这些区间即可
    注意到，这些区间是包含关系，可以用上上面的结论，只要检查a[i-2]-a[i],a[i-1]-a[i]即可
    然而到这其实只考虑了题目中条件的第二种符合情况
    对于第一种，有两种考虑方式：
        1.既然只要考虑倒数两位，那么不妨把条件1作为一个状态存储，变成4状态的dp，见题解和tourist的代码
        2.可以在每次不选择的时候将区间的左端点调整，这样可以确保始终是只要考虑第二种的情况，见jiangly的代码
*/

#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define fore(i, l, r) for (int i = int(l); i <= int(r); ++i)
#define sz(a) int((a).size())
#define endl "\n"
#define pii pair<int,int>

using namespace std;
using ll = long long;

const int N = 5e4+10;
int dp[N][2];

void solve(){
    int n,x;
    cin>>n;
    vector<int> a(n);
    forn(i,n) cin>>a[i];
    cin>>x;
    forn(i,n) a[i] -= x;
    vector<int> dp(4,-1);
    dp[0] = 0;
    forn(i,n){
        vector<int> dp2(4,-1);
        forn(t,4){
            if(dp[t]<0) continue;
            int p0 = t&1;
            int p1 = (t>>1)&1;
            forn(p2,2){
                if(i>0 && p2>0 && p1>0 && a[i]+a[i-1]<0) continue;
                if(i>1 && p2>0 && p1>0 && p0>0 && a[i]+a[i-1]+a[i-2]<0) continue;
                dp2[p1+2*p2] = max(dp2[p1+2*p2],dp[t]+p2);
            }
        }
        swap(dp,dp2);
    }
    cout<<*max_element(dp.begin(),dp.end())<<endl;
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