#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve(){
    string s;
    cin>>s;
    vector<int> a;
    for(int i=0;i<s.size();++i) a.push_back(s[i]-'0');
    bool even = false;
    for(int i=0;i<a.size();++i){
        if(a[i]%2==0){
            even = true;
            break;
        }
    }
    if(!even) cout<<-1<<endl;
    else{
        if(a.back()%2==0) cout<<0<<endl;
        else if(a.front()%2==0) cout<<1<<endl;
        else cout<<2<<endl;
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