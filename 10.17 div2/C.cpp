#include <bits/stdc++.h>

using namespace std;
using ll = long long;


const ll N = 1e6+10;
int n,m;
ll tr[N];

// sum of [0,x)
ll sum(ll x){
    ll res = 0;
    for(ll i=x;i>0;i-=i&-i){
        res += tr[i-1];
    }
    return res;
}

// a[p] += x;
void add(ll p,ll x){
    for(ll i=p+1;i<=m;i+=i&-i){
        tr[i-1] += x;
    }
}

void solve(){
    cin>>n>>m;
    vector<string> mp;
    string s;
    for(int i=0;i<n;++i){
        cin>>s;
        mp.push_back(s);
    }
    for(int j=0;j<m-1;++j){
        for(int i=0;i<n;++i){
            if(mp[i][j]=='.') continue;
            if(i-1>=0 && mp[i-1][j+1]=='X'){
                // tr.add() a[j]+=1
                add(j,1);
                // cout<<j<<" ";
                break;
            }
            // if(i+1<n && mp[i+1][j+1]=='X'){
            //     add(j,1);
            //     // cout<<j<<" ";
            //     break;
            // }
        }
    }
    // cout<<endl;
    int q;
    cin>>q;
    for(int i=0,a,b;i<q;++i){
        cin>>a>>b;
        if(a==b){
            cout<<"YES"<<endl;
            continue;
        }
        a--,b--;
        if(sum(b)-sum(a)>=1){
            cout<<"NO"<<endl;
        }
        else cout<<"YES"<<endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    tt = 1;
    while (tt--) {
        solve();
    }

    return 0;
}