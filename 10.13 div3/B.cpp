#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve(){
    string s;
    cin>>s;
    int i2 = -1,i5 = -1,i7 = -1,i0 = -1,i00 = -1;
    int n = s.size();
    for(int i=0;i<s.size();++i){
        // if(s[i]=='2') i2 = i;
        if(s[i]=='5') i5 = i;
        // else if(s[i]=='7') i7 = i;
        else if(s[i]=='0') i0 = i;
    }
    int ans = 20;
    if(i5 != -1){
        for(int i=i5-1;i>=0;--i){
            if(s[i]=='2'){
                i2 = i;
                break;
            }
            else if(s[i]=='7'){
                i7 = i;
                break;
            }
        }
        if(i2!=-1){
            ans = min(ans,-i2-1+n-1);
        }
        if(i7!=-1){
            ans = min(ans,-i7-1+n-1);
            // cout<<"i7 "<<i7<<" "<<ans<<endl;
        }
    }
    if(i0 != -1){
        i5 = -1, i00 = -1;
        for(int i=i0-1;i>=0;--i){
            if(s[i]=='0'){
                i00 = i;
                break;
            }
            else if(s[i]=='5'){
                i5 = i;
                break;
            }
        }
        if(i00!=-1){

            ans = min(ans,-i00-1+n-1);
            // cout<<"i00 "<<i00<<" "<<ans<<endl;
        }
        if(i5!=-1){
            ans = min(ans,-i5-1+n-1);
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