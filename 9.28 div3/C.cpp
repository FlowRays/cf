#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n,m,k;
int mp[20][20];
int rec[20][20];

bool cro(int i,int j){
    return (i<0 || j<0 || i>=n || j>=m);
}

bool ok(int x,int y,int d){
    for(int i=x,j1=y,j2=y;i>=x-d;i--,j1--,j2++){
        if(cro(i,j1) || cro(i,j2)) return false;
        if(!mp[i][j1] || !mp[i][j2]) return false;
    }
    return true;
}

void tc(int x,int y,int d){
    for(int i=x,j1=y,j2=y;i>=x-d;i--,j1--,j2++){
        rec[i][j1] = rec[i][j2] = 1;
    }    
}

void solve(){
    cin>>n>>m>>k;
    char ch;
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            cin>>ch;
            mp[i][j] = (ch=='*' ? 1 : 0);
            rec[i][j] = 0;
        }
    }
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            for(int d=k;d<n;++d){
                if(ok(i,j,d)) tc(i,j,d);
            }
        }
    }
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if(mp[i][j]==1 && !rec[i][j]){
                cout<<"NO"<<endl;
                return;
            }
        }
    }
    cout<<"YES"<<endl;
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