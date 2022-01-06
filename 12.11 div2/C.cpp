// https://codeforces.com/blog/entry/97782?#comment-865873
#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define fore(i, l, r) for (int i = int(l); i <= int(r); ++i)
#define sz(a) int((a).size())
#define endl "\n"

using namespace std;
using ll = long long;

struct player{
    int id,ans=0;
    int a,b;
    bool operator< (const player &x) const{
        return a>x.a;
    }
};

void solve(){
    int n;
    cin>>n;
    vector<player> p(n);
    vector<int> ma(n),mi(n);
    forn(i,n){
        p[i].id = i;
        cin>>p[i].a;
    }
    forn(i,n) cin>>p[i].b;
    sort(p.begin(),p.end());
    forn(i,n) mi[i] = (i==0 ? p[i].b : min(mi[i-1],p[i].b));
    for(int i=n-1;i>=0;--i) ma[i] = (i==n-1 ? p[i].b : max(ma[i+1],p[i].b));
    p[0].ans = 1;
    fore(i,1,n-1){
        if(ma[i]>mi[i-1]) p[i].ans = 1;
        else break;
    }
    vector<int> ans(n);
    forn(i,n) ans[p[i].id] = p[i].ans;
    forn(i,n) cout<<ans[i];
    cout<<endl;
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