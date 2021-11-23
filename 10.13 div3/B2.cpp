#include <bits/stdc++.h>

using namespace std;
using ll = long long;

string s[4] = {"25","50","75","00"};

void solve(){
    string t;
    cin>>t;
    int ans = 20;
    for(int i=0;i<4;++i){
        int p = 1;
        for(int j=t.size()-1;j>=0;--j){
            if(t[j]==s[i][p]) p--;
            if(p==-1){
                ans = min(ans,int(t.size()-j-2));
                break;
            }
        }
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