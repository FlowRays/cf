#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve(){
    string s,t;
    cin>>s>>t;
    map<char,int> mp;
    for(int i=0;i<s.size();++i) mp[s[i]] = i;
    int ans = 0;
    for(int i=1;i<t.size();++i){
        ans += abs(mp[t[i]]-mp[t[i-1]]);
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