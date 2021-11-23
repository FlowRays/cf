#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int inf = 1<<29;

void solve(){
    int n;
    string s;
    cin>>n>>s;
    if(s==string(s.rbegin(),s.rend())){
        cout<<0<<endl;
        return;
    }
    int ans = inf;
    map<char,int> mp;
    for(auto ch: s) mp[ch]++;
    for(auto [ch,y]: mp){
        // if(ch != 'd') continue;
        string t;
        for(int i=0;i<n;++i){
            if(s[i]!=ch) t.push_back(s[i]);
        }
        if(t==string(t.rbegin(),t.rend())){
            vector<int> v;
            int i = 0;
            int cnt;
            int res = 0;
            bool ok = false;
            for(;i<s.size();++i){
                cnt = 0;
                while(i<s.size() && s[i]==ch){
                    i++;
                    cnt++;
                }
                if(i==s.size()) ok = true;
                v.push_back(cnt);
            }
            // cnt = 0;
            // while(i<s.size() && s[i]==ch){
                // i++;
                // cnt++;
            // }
            if(!ok)
                v.push_back(0);
            // cout<<ch<<endl;
            // for(auto x: v) cout<<x<<" ";
            // cout<<endl;
            for(int p=0,q=v.size()-1;p<q;++p,--q){
                res += abs(v[p]-v[q]);
            }
            ans = min(ans,res);
            // cout<<"ans: "<<ans<<" ch: "<<ch<<endl;
        }
    } 
    if(ans==inf) cout<<-1<<endl;
    else cout<<ans<<endl;
}

/*
1
10
dddadbbdda
*/

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