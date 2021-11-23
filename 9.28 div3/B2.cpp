#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(auto& x: a) cin>>x;
    vector<int> b = a;
    sort(b.begin(),b.end());
    vector<tuple<int,int,int>> res;
    for(int i=0;i<n;++i){
        if(a[i]!=b[i]){
            int idx = min_element(a.begin()+i,a.end())-a.begin();
            rotate(a.begin()+i,a.begin()+idx,a.end());
            res.emplace_back(i+1,n,idx-i);
        }
    }
    cout<<res.size()<<endl;
    for(auto [l,r,d]: res){
        cout<<l<<" "<<r<<" "<<d<<endl;
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