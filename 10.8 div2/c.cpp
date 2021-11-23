#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve(){
    int n;
    char ch;
    string s;
    cin>>n>>ch>>s;
    // int t = n/2;
    bool ok = true;
    for(int i=0;i<n;++i){
        if(s[i]!=ch){
            ok = false;
            break;
        }
    }
    if(ok){
        cout<<0<<endl;
        return;
    }
    for(int i=n/2+1;i<=n;++i){
        if(s[i-1]==ch){
            cout<<1<<endl;
            cout<<i<<endl;
            return;
        }
    }
    cout<<2<<endl;
    cout<<n-1<<" "<<n<<endl;
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