#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int f[1010];
int find(int x) {
  if (x != f[x])  // x 不是自身的父亲，即 x 不是该集合的代表
    f[x] = find(f[x]);  // 查找 x 的祖先直到找到代表，于是顺手路径压缩
  return f[x];
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,d;
    cin>>n>>d;
    for(int i=1;i<=n;++i) f[i]=i;
    int x,y;
    for(int i=1;i<=d;++i){
        cin>>x>>y;
        if(find(x)!=find(y))
            f[find(x)] = find(y);
        map<int,int> mp;
        for(int i=1;i<=n;++i){
            if(i!=find(i))
                mp[find(i)]++;
        }
        int sz = mp.size();
        int s = 0;
        vector<int> t;
        for(auto [x,y]: mp){
            s += y+1;
            t.push_back(y+1);
        }
        int bs = i-(s-sz);
        // cout<<" "<<s<<" "<<sz<<" "<<i<<" "<<bs<<endl;
        if(bs+1>=sz) cout<<i<<endl;
        else{
            sort(t.begin(),t.end(),greater<int>());
            ll ans = 0;
            for(int i=0;i<bs+1;++i) 
                ans += t[i];
            cout<<ans-1<<endl;
        }
    }


    return 0;
}