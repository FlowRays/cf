#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve(){
    string s;
    cin>>s;
    // ab bc
    int n = s.size();
    if(n%2==1){
        cout<<"NO"<<endl;
        return;
    }
    int a = 0, b = 0, c = 0;
    for(int i=0;i<n;++i){
        if(s[i]=='A') a++;
        else if(s[i]=='B') b++;
        else c++;
    }
    if(a+c==b) cout<<"YES"<<endl;
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