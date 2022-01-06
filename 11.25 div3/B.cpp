#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve(){
    ll a,b;
    cin>>a>>b;
    cout<<min(min(a,b),(a+b)/4)<<endl;
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