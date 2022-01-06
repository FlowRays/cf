#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define fore(i, l, r) for (int i = int(l); i <= int(r); ++i)
#define sz(a) int((a).size())
#define endl "\n"
#define pii pair<int,int>

using namespace std;
using ll = long long;

void solve(){
    int n;
    cin>>n;
    vector<string> v(n-2);
    forn(i,n-2) cin>>v[i];
    string ans;
    ans.push_back(v[0][0]);
    bool ok = false;
    forn(i,n-3){
        if(v[i][1] == v[i+1][0]) ans.push_back(v[i][1]);
        else{
            ok = true;
            ans.push_back(v[i][1]);
            ans.push_back(v[i+1][0]);
        }
    }
    ans.push_back(v.back()[1]);
    if(!ok) ans.push_back('a');
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