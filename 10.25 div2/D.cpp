#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

// 这题其实并不难，没必要陷入题解，自己仔细想想，相信自己

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    vector<int> a(n+1),b(n+1),dp(n+1),vis(n+1,0),pre(n+1,-1);
    for(int i=1;i<=n;++i) cin>>a[i];
    for(int i=1;i<=n;++i) cin>>b[i];
    dp[n] = 0;
    vis[n] = 1;
    queue<int> q;
    q.push(n);
    int mmax = n;
    while(q.size()){
        int x = q.front();
        int i = x+b[x];
        q.pop();
        // cout<<" "<<x<<" "<<dp[x]<<endl;
        if(i-a[i]<=0){
            cout<<dp[x]+1<<endl;
            vector<int> path;
            path.push_back(0);
            while(x!=n && x!=-1){
                path.push_back(x);
                x = pre[x];
            }
            for(auto it=path.rbegin();it!=path.rend();++it)
                cout<<*it<<" ";
            cout<<endl;
            return 0;
        }
        for(int j=i-a[i];j<=min(i,mmax);++j){
            // int t = j+b[j];
            if(dp[j]!=0) continue;
            dp[j] = dp[x]+1; 
            q.push(j);
            // cout<<"  "<<j<<endl;
            pre[j] = x;
        }
        mmax = min(mmax,i-a[i]);
    }
    cout<<-1<<endl;

    return 0;
}