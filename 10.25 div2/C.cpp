#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve(){
    int n;
    cin>>n;
    int a[32] = {0};
    bool check = true;
    for(int i=0,x;i<n;++i){
        cin>>x;
        if(x!=0) check=false;
        int j = 0;
        while(x>0){
            a[j++] += (x&1);
            x>>=1;
        }
    }
    if(check){
        for(int i=1;i<=n;++i) cout<<i<<" ";
        cout<<endl;
        return;
    }
    map<int,int> mp;
    for(int i=0;i<32;++i){
        if(a[i]==0) continue;
        mp[a[i]]++;
    }
    int m = mp.begin()->first;
    for(int i=1;i<=m;++i){
        bool ok = true;
        for(auto [x,y]: mp){
            if(x%i){
                ok = false;
                break;
            }
        }
        if(ok) cout<<i<<" ";
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