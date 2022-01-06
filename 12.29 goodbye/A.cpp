#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define fore(i, l, r) for (int i = int(l); i <= int(r); ++i)
#define sz(a) int((a).size())
#define endl "\n"
#define pii pair<int,int>

using namespace std;
using ll = long long;

int vis[110];

void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    memset(vis,0,sizeof(vis));
    forn(i,n) cin>>a[i];
    forn(i,n) a[i] = abs(a[i]);
    int cnt = 0;
    forn(i,n){
        vis[a[i]]++;
    }
    forn(i,101){
        if(i==0){
            if(vis[i]>0) cnt++;
        } 
        else{
            cnt += min(vis[i],2);
        }
    }
    cout<<cnt<<endl;
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