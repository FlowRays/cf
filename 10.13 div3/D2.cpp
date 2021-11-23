#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    map<int,int> mp;
    for(int i=0;i<n;++i){
        cin>>a[i];
        mp[a[i]]++;
    }
    for(auto [x,y]: mp){
        if(y>=n/2){
            cout<<-1<<endl;
            return;
        }
    }
    vector<int> p;
    for(int i=0;i<n;++i){
        for(int j=i+1;j<n;++j){
            int t = abs(a[i]-a[j]);
            for(int k=1;k*k<=t;++k){
                if(t%k==0){
                    p.push_back(k);
                    p.push_back(t/k);
                }
            }
        }
    }
    sort(p.begin(),p.end());
    int num = unique(p.begin(),p.end()) - p.begin();
    int ans = 1;
    for(int i=0;i<num;++i){
        int t = p[i];
        map<int,int> cnt;
        // cout<<t<<":"<<endl;
        for(int j=0;j<n;++j){
            int k = a[j]%t;
            k += 2*t;
            k %= t;
            cnt[k]++;
            // cout<<a[j]<<": "<<k<<endl;
        }
        for(auto [x,y]: cnt){
            if(y>=n/2){
                ans = max(ans,t);
                break;
            }
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