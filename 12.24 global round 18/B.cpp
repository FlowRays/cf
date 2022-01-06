#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define fore(i, l, r) for (int i = int(l); i <= int(r); ++i)
#define sz(a) int((a).size())
#define endl "\n"
#define pii pair<int,int>

using namespace std;
using ll = long long;

const int N = 2e5+10;
int cnt[N][20];

// count the number of 1 in the k-th bit
int count(int n,int k){
    int res = (n >> (k + 1)) << k;
    if ((n >> k) & 1)
        res += n & ((1ll << k) - 1);
    return res;
}

// O(logr)
void solve(){
    int l,r;
    cin>>l>>r;
    int ans = 1e9;
    forn(i,20){
        int t = count(r+1,i)-count(l,i);
        ans = min(ans,r-l+1-t);
    }
    cout<<ans<<endl;
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