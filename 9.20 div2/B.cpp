#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve(){
    int a,b,c;
    int k;
    cin>>a>>b>>c>>k;
    int s = a+b+c;
    int m = max(a,max(b,c));
    int l = 2*m-s-1, r = s-3;
    if(k>=l && k<=r) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
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