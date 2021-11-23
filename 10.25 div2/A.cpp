#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve(){
    string s;
    cin>>s;
    map<char,int> mp;
    for(auto ch: s) mp[ch]++;
    char tmp;
    for(char i='a';i<='z';++i){
        if(mp[i]){
            tmp = i;
            cout<<i<<" ";
            break;
        }
    }
    // cout<<endl<<tmp<<endl;
    for(auto ch: s){
        if(ch==tmp) tmp='*';
        else{
            cout<<ch;
        }
    }
    cout<<endl;
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