#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define fore(i, l, r) for (int i = int(l); i <= int(r); ++i)
#define sz(a) int((a).size())
#define endl "\n"
#define pii pair<int,int>

using namespace std;
using ll = long long;

const double eps = 1e-6;

void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    forn(i,n) cin>>a[i];
    if(n<=2){
        cout<<0<<endl;
        return;
    }
    int ans = 10000;
    forn(i,n-1){
        fore(j,1,n-1){
            if(i==j) continue;
            double d = (a[j]-a[i])*1.0/(j-i);
            int cnt = 0;
            forn(k,n){
                if(abs(a[k]-(a[i]+(k-i)*d)) > eps){
                    cnt++;
                } 
            }
            // cout<<d<<" "<<cnt<<endl;
            ans = min(ans,cnt);
        }
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