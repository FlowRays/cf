#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve(){
    int n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    int xl=0,xr=0,yl=0,yr=0,x=0,y=0;
    int ans = 0;
    for(int i=0;i<s.size();++i){
        if(s[i]=='L') x--;
        else if(s[i]=='R') x++;
        else if(s[i]=='U') y--;
        else y++;
        xl = min(xl,x);
        xr = max(xr,x);
        yl = min(yl,y);
        yr = max(yr,y);
        if(xr-xl>=m || yr-yl>=n){
            if(s[i]=='L') xl++;
            else if(s[i]=='U') yl++;
            cout<<abs(yl)+1<<" "<<abs(xl)+1<<endl;
            return;
        }
    }
    cout<<abs(yl)+1<<" "<<abs(xl)+1<<endl;

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