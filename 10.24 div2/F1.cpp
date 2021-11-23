// dp

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int ans[512];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    vector<int> a(n);
    map<int,int> mp[510],ans;
    for(int i=0;i<n;++i) cin>>a[i];
    for(int i=0;i<n;++i){
        ans[a[i]] = 1;
        mp[a[i]][a[i]] = 1;
        for(int j=1;j<a[i];++j){
            for(auto [x,y]: mp[j]){
                mp[a[i]][x^a[i]] = 1;
                ans[x^a[i]] = 1;
            }
        }
    }
    int cnt = 0;
    ans[0] = 1;
    for(int i=0;i<=512;++i){
        if(ans[i]) cnt++; 
    }
    cout<<cnt<<endl;
    for(int i=0;i<=512;++i){
        if(ans[i]) cout<<i<<" ";
    }
    cout<<endl;

    return 0;
}