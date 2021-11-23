#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;++i) cin>>a[i];
    ll x = 2;
    bool ok = true;
    for(int i=0;i<n;++i){
        if(a[i]%x==0){
            ok = false;
            break;
        }
        x = lcm(x,i+3);
        // x *= (i+3);
        if(x>1e9) break;
    }
    if(ok) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    // for(int i=0;i<n;++i){
    //     bool found = false;
    //     for(int j=a.size()-1;j>=0;--j){
    //         if(a[j]%(j+2)!=0){
    //             found = true;
    //             a.erase(a.begin()+j);
    //             break;
    //         }
    //     }
    //     if(!found){
    //         cout<<"NO"<<endl;
    //         return;
    //     }
    //     for(auto x: a) cout<<x<<" ";
    //     cout<<endl;
    // }
    // cout<<"YES"<<endl;
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