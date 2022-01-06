#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define fore(i, l, r) for (int i = int(l); i <= int(r); ++i)
#define sz(a) int((a).size())
#define endl "\n"
#define pii pair<int,int>

using namespace std;
using ll = long long;

void solve(){
    vector<int> b(7);
    forn(i,7) cin>>b[i];
    // x,y,z,x+y,x+z,y+z,x+y+z 中 x+y,x+z,y+z 必然是不可能是最小或者第二小的
    cout<<b[0]<<" "<<b[1]<<" "<<b.back()-b[0]-b[1]<<endl;
    // int x[2]={0,5},y[2]={1,4},z[2]={2,3};
    // auto test = [&](int x,int y, int z){
    //     vector<int> b2 = {x,y,z,x+y,x+z,y+z,x+y+z};
    //     sort(b2.begin(),b2.end());
    //     return b==b2;
    // };
    // forn(i,2){
    //     forn(j,2){
    //         forn(k,2){
    //             // cout<<"??"<<" "<<b[x[i]]<<" "<<b[y[j]]<<" "<<b[z[k]]<<endl;
    //             bool ok = test(b[x[i]],b[y[j]],b[z[k]]);
    //             if(ok){
    //                 cout<<b[x[i]]<<" "<<b[y[j]]<<" "<<b[z[k]]<<endl;
    //                 return;
    //             }
    //         }
    //     }
    // }
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
