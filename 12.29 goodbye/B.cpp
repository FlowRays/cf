#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define fore(i, l, r) for (int i = int(l); i <= int(r); ++i)
#define sz(a) int((a).size())
#define endl "\n"
#define pii pair<int,int>

using namespace std;
using ll = long long;

void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    string ans;
    ans.push_back(s[0]);
    fore(i,1,n-1){
        if(i==1){
            if(s[i]<s[i-1])
                ans.push_back(s[i]);
            else
                break;
        }
        else{
            if(s[i]<=s[i-1])
                ans.push_back(s[i]);
            else
                break;
        }

    }   
    cout<<ans;
    reverse(ans.begin(),ans.end());
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