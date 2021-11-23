#include <bits/stdc++.h>

using namespace std;
using ll = long long;

pair<int,int> f(string s){
    int ab = 0, ba = 0;
    for(int i=0;i<s.size()-1;++i){
        if(s[i]=='a' && s[i+1]=='b'){
            ab++;
        }
        else if(s[i]=='b' && s[i+1]=='a'){
            ba++;
        }
    }
    return make_pair(ab,ba);
}

void solve(){
    string s;
    cin>>s;
    int n = s.size()-1;
    auto x = f(s);
    if(x.first == x.second){
        cout<<s<<endl;
        return;
    }
    s[0] = (s[0]=='a' ? 'b' : 'a');
    x = f(s);
    if(x.first == x.second){
        cout<<s<<endl;
        return;
    }
    s[0] = (s[0]=='a' ? 'b' : 'a');
    s[n] = (s[n]=='a' ? 'b' : 'a');
    x = f(s);
    if(x.first == x.second){
        cout<<s<<endl;
        return;
    }
    s[0] = (s[0]=='a' ? 'b' : 'a');
    x = f(s);
    if(x.first == x.second){
        cout<<s<<endl;
        return;
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