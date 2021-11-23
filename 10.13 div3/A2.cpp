#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve(){
    int a[3];
    for(int i=0;i<3;++i) cin>>a[i];
    for(int i=0;i<3;++i){
        int s = 0;
        for(int j=0;j<3;++j){
            if(i!=j) s = max(s,a[j]);
        }
        cout<<max(0,s+1-a[i])<<(i==2 ? '\n' : ' ');
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