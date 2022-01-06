#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve(){
    int x[2],p[2],ws[2],w[2];
    cin>>x[0]>>p[0];
    cin>>x[1]>>p[1];
    int t[2] = {x[0],x[1]};
    for(int i=0;i<2;++i){
        int cnt = 0;
        while(t[i]){
            cnt++;
            t[i]/=10;
        }
        w[i] = cnt;
        ws[i] = cnt;
    }
    int m = max(ws[0],ws[1]);
    ws[0] += p[0];
    ws[1] += p[1];
    if(ws[0]<ws[1]) cout<<"<";
    else if(ws[0]>ws[1]) cout<<">";
    else{
        if(x[0]==x[1] && p[0]==p[1]) cout<<"=";
        else{
            for(int i=0;i<2;++i){
                if(w[i]!=m){
                    for(int j=0;j<m-w[i];++j) x[i]*=10;
                }
            }
            if(x[0]<x[1]) cout<<"<";
            else if(x[0]>x[1]) cout<<">";
            else cout<<"=";
        }
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