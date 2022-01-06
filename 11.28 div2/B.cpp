#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve(){
    int n,q;
    cin>>n>>q;
    string s;
    cin>>s;
    int now = 0;
    for(int i=2;i<s.size();++i){
        if(s.substr(i-2,3)=="abc") now++;
    }
    // cout<<now<<endl;
    int pos;
    char ch;
    for(int i=1;i<=q;++i){
        cin>>pos>>ch;
        bool before = false;
        if(pos-2>=1 && pos<=n && s.substr(pos-3,3)=="abc") before = true;
        else if(pos-1>=1 && pos+1<=n && s.substr(pos-2,3)=="abc") before=true;
        else if(pos+2<=n && s.substr(pos-1,3)=="abc") before=true;
        s[pos-1] = ch;
        bool after = false;
        if(pos-2>=1 && pos<=n && s.substr(pos-3,3)=="abc") after = true;
        else if(pos-1>=1 && pos+1<=n && s.substr(pos-2,3)=="abc") after=true;
        else if(pos+2<=n && s.substr(pos-1,3)=="abc") after=true;
        if(before == after) cout<<now<<endl;
        else if(!before && after){
            now++;
            cout<<now<<endl;
        }
        else{
            now--;
            cout<<now<<endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt = 1;
    // cin >> tt;
    while (tt--) {
        solve();
    }

    return 0;
}