#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;++i) cin>>a[i];
    vector<pair<int,int>> p(n);
    for(int i=0;i<n;++i){
        p[i] = make_pair(-a[i],i+1);
    }
    sort(p.begin(),p.end());
    deque<pair<int,int>> dq;
    int l = 0, r = 0;
    dq.emplace_front(0,0);
    ll ans = 0;
    for(int i=0;i<n;++i){
        if(i%2==0){
            dq.emplace_front(--l,p[i].second);
            ans += a[p[i].second-1]*2ll*abs(l);
        }
        else{
            dq.emplace_back(++r,p[i].second);
            ans += a[p[i].second-1]*2ll*abs(r);
        }
    }
    vector<int> aa(n+1);
    for(auto [x,y]: dq){
        aa[y] = x;
    }
    cout<<ans<<endl;
    for(auto x: aa) cout<<x<<" ";
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