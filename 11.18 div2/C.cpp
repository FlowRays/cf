#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve(){
    int n;
    cin>>n;
    vector<int> a(n),b(n);
    for(auto& x: a) cin>>x;
    for(auto& x: b) cin>>x;
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    for(int i=0;i<n;++i){
        if(b[i]-a[i]>=0 && b[i]-a[i]<=1) continue;
        cout<<"NO"<<endl;
        return;
    }
    cout<<"YES"<<endl;
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