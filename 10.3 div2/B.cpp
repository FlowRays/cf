#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve(){
    int n,x;
    cin>>n>>x;
    vector<int> a(n),b(n);
    for(int i=0;i<n;++i){
        cin>>a[i];
        b[i] = a[i];
    }
    sort(b.begin(),b.end());
    bool ok = true;
    for(int i=n-x;i<x;++i){
        if(a[i]!=b[i]){
            ok = false;
            break;
        }
    }
    if(ok) cout<<"YES"<<endl;
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