#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(auto& x: a) cin>>x;
    if(a == vector<int>(a.rbegin(),a.rend())){
        cout<<"YES\n";
        return;
    }
    bool ok = false;
    auto Test = [&](int x){
        vector<int> b;
        for(int i=0;i<n;++i){
            if(a[i]!=x) b.push_back(a[i]);
        }
        ok |= (b == vector<int>(b.rbegin(),b.rend()));
    };
    for(int i=0;i<n;++i){
        if(a[i] != a[n-1-i]){
            Test(a[i]);
            Test(a[n-1-i]);
            break;
        }
    }
    cout<<(ok ? "YES" : "NO")<<endl;
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