#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve(){
    int n;
    string s,t;
    cin>>n>>s;
    t = s;
    sort(t.begin(),t.end());
    if(s==t) cout<<0<<endl;
    else{
        cout<<1<<endl;
        int cnt = 0;
        for(int i=0;i<n;++i){
            if(s[i]!=t[i]){
                cnt++;
            }
        }
        cout<<cnt<<" ";
        for(int i=0;i<n;++i){
            if(s[i]!=t[i]){
                cout<<i+1<<" ";
            }
        }
        cout<<endl;
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