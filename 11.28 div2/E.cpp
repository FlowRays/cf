#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct binary_indexed_tree{
    int N;
    vector<ll> bit;
    binary_indexed_tree(int n):N(n){
        bit.resize(N+1,0);
    }
    // 单点+y
    void add(int x,ll a){
        for(; x<=N; x+=(x&-x)) bit[x] += a;
    }
    // 前缀和
    ll sum(int x){
        ll ret=0;
        for(; x>0; x-=(x&-x)) ret += bit[x];
        return ret;
    }
}A,B,C;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,q;
    cin>>n>>q;
    string s;
    cin>>s;
    for(int i=0;i<s.size();++i){
        if(s[i]=='a') A.add(i+1,1);
        else if(s[i]=='b') B.add(i+1,1);
        else C.add(i+1,1);
    }
    int now = 0;
    int pos;
    char ch;
    for(int i=1;i<=q;++i){
        cin>>pos>>ch;
    }

    return 0;
}