#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve(){
    int n;
    cin>>n;
    vector<int> a(n),b(n+1,0),r(n+1,0);
    for(int i=0;i<n;++i) cin>>a[i];
    string s;
    cin>>s;
    for(int i=0;i<n;++i){
        if(s[i]=='B'){
            if(a[i]<1){
                cout<<"NO"<<endl;
                return;
            }
            if(a[i]<=n)
                b[a[i]<1 ? 1 : a[i]]++;
        }
        else{
            if(a[i]>n){
                cout<<"NO"<<endl;
                return;
            }
            if(a[i]>=1)
                r[a[i]>n ? n : a[i]]++;
        }
    }
    for(int i=1;i<=n;++i){
        b[i] += b[i-1];
    }
    for(int i=n-1;i>=1;--i){
        r[i] += r[i+1];
    }
    for(int i=1;i<=n;++i){
        if(b[i]>i || r[i]>n-i+1){
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
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