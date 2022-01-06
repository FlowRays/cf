#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;++i) cin>>a[i];
    sort(a.begin(),a.end());
    int cnt = 0;
    int tar = n/2;
    for(int i=1;i<n;++i){
        cout<<a[i]<<" "<<a[0]<<endl;
        cnt++;
        if(cnt==tar) return;
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