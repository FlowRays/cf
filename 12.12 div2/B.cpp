#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define fore(i, l, r) for (int i = int(l); i <= int(r); ++i)
#define sz(a) int((a).size())
#define endl "\n"

using namespace std;
using ll = long long;

void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    forn(i,n){
        cin>>a[i];
    }
    int m = *max_element(a.begin(),a.end());
    int cnt = 0;
    int tar = a[n-1];
    if(tar == m){
        cout<<0<<endl;
        return;
    }
    for(int i=n-2;i>=0;--i){
        if(a[i]>tar){
            tar = a[i];
            cnt++;
            if(tar == m){
                cout<<cnt<<endl;
                return;
            }
        }
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