#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;++i) cin>>a[i];
    if(count(a.begin(),a.end(),a[0])==n){
        cout<<-1<<endl;
        return;
    }
    int ans = abs(a[0]-a[1]);
    // for(int i=0;i<n;++i){
    //     for(int j=i+1;j<n;++j){
    //         ans = __gcd(ans,abs(a[j]-a[i]));
    //     }
    // }
    for(int i=2;i<n;++i){
        ans = __gcd(ans,abs(a[i]-a[i-1])); // 和0做gcd=另一个数
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