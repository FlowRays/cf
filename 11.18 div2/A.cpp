#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve(){
    ll u,v;
    cin>>u>>v;
    if(u==v) cout<<1<<" "<<-1<<endl;
    else cout<<-u*u<<" "<<v*v<<endl;
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