#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve(){
    int n;
    cin>>n;
    char ch;
    ll ans = 0;
    for(int i=0;i<n;++i){
        cin>>ch;
        if(i<n-1 && ch-'0'>0){
            ans += 1+ch-'0';
        }
        else{
            ans += ch-'0';
        }
    }
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