#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve(){
    int a,b,c;
    cin>>a>>b>>c;
    a%=2; b%=2; c%=2;
    if( (!a && !b && c) || (!a && b && c) || (a && !b && !c) || (a && b && !c) )
        cout<<1<<endl;
    else cout<<0<<endl;
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