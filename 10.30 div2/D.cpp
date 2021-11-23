#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve(){
    ll x,y;
    cin>>x>>y;
    if(x>y) cout<<x+y<<endl;
    else if(x==y) cout<<x<<endl;
    else{
        cout<<y-y%x/2<<endl;
    }
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