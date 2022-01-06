#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve(){
    int n;
    cin>>n;
    vector<int> a(n),b(n);
    for(int i=0;i<n;++i) cin>>a[i]>>b[i];
    int l=0,r=n;
    auto check = [&](int x){
        // cout<<" "<<x<<endl;
        int p = 0;
        for(int i=0;i<x;++i){
            while(p<n){
                if(i>=x-1-a[p] && i<=b[p]) break;
                p++;
            }
            // cout<<"  "<<p<<endl;
            if(p>=n) return false;
            p++;
        }
        return true;
    };
    while(l<r){
        int mid = (l+r+1)>>1;
        if(check(mid)) l=mid;
        else r=mid-1;
    }
    cout<<l<<endl;
}

/*
1
9
8 6
3 5
6 8
6 3
6 3
3 2
5 1
2 3
3 8
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