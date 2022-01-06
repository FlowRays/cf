#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define fore(i, l, r) for (int i = int(l); i <= int(r); ++i)
#define sz(a) int((a).size())
#define endl "\n"
#define pii pair<int,int>

using namespace std;
using ll = long long;

void solve(){
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    forn(i,n) cin>>a[i];
    sort(a.begin(),a.end());
    int ans = 1e9;
    forn(i,k+1){
        int s = 0;
        for(int j=0;j<i;++j){
            s += a[n-1-j-i]/a[n-1-j];
        }
        for(int j=0;j<k-i;++j){
            s += a[j]/a[n-1-2*i-j];
        }
        for(int j=k-i;j<=n-1-2*i-(k-i);++j) s += a[j];
        // forn(p,n) cout<<a[p]<<" ";
        // cout<<endl;
        // cout<<" "<<s<<endl;
        ans = min(ans,s);
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