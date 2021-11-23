#include <bits/stdc++.h>

using namespace std;
using ll = long long;

using pii = pair<int,int>;

void solve(){
    int n;
    cin>>n;
    int x;
    priority_queue<pii,vector<pii>> q;
    for(int i=0;i<n;++i){
        cin>>x;
        if(x>0) q.push(make_pair(x,i+1));
    }
    vector<pii> ans;
    while(q.size()>1){
        pii p1 = q.top(); q.pop();
        pii p2 = q.top(); q.pop();
        ans.push_back(make_pair(p1.second,p2.second));
        if(p1.first>1) q.push(make_pair(p1.first-1,p1.second));
        if(p2.first>1) q.push(make_pair(p2.first-1,p2.second));
    }
    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();++i) cout<<ans[i].first<<" "<<ans[i].second<<endl;
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