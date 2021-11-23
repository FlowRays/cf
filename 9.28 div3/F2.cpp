#include <bits/stdc++.h>

using namespace std;
using ll = long long;

// from dd: 
// 维护一个0位置的队列，每次把队列里0的下一个偏置位置的1污染，并加入队列
// 注意: 每个位置的1只会污染一次
void solve(){
    int n,d;
    cin>>n>>d;
    vector<int> a(n),nxt(n);
    queue<int> q;
    for(int i=0;i<n;++i){
        cin>>a[i];
        if(!a[i]) q.push(i);
        nxt[i] = (i-d+n)%n;
    }
    int ans = 0;
    while(q.size()){
        int cnt = q.size();
        while(cnt--){
            int t = q.front();
            q.pop();
            if(a[nxt[t]]){
                a[nxt[t]] = 0;
                q.push(nxt[t]);
            }
        }
        if(q.size()) ans++;
    }
    if(count(a.begin(),a.end(),1)!=0) ans = -1;
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