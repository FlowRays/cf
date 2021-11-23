#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve(){
    int n;
    cin>>n;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=i;++j) cout<<"(";
        for(int j=1;j<=i;++j) cout<<")";
        for(int j=1;j<=n-i;++j) cout<<"(";
        for(int j=1;j<=n-i;++j) cout<<")";
        cout<<endl;
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