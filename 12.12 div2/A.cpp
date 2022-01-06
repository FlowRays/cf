#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define fore(i, l, r) for (int i = int(l); i <= int(r); ++i)
#define sz(a) int((a).size())
#define endl "\n"

using namespace std;
using ll = long long;

void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    forn(i,n) cin>>a[i];
    ll ans = 1;
    forn(i,n){
        if(i==0) ans += a[i];
        else{
            if(a[i]==0 && a[i-1]==0){
                cout<<-1<<endl;
                return;
            }
            else if(a[i]==1 && a[i-1]==1) ans += 5;
            else ans += a[i];
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