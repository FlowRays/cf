/*
二维前缀和
猜测/? a,b范围
我感觉我这个是错解
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

char s[410][410];
int A[410][410];
int B[410][410];

void solve(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;++i) cin>>s[i];
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            A[i][j] = (s[i][j-1]=='1' ? 1 : 0);
            B[i][j] = B[i-1][j]+B[i][j-1]-B[i-1][j-1]+A[i][j];
        }
    }
    int ans = 16;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            for(int a=5;a<=10;++a){
                int x = i+a-1;
                if(x>n) break;
                for(int b=4;b<=10;++b){
                    int y = j+b-1;
                    if(y>m) break;
                    int a1 = B[x-1][j]-B[x-1][j-1]-B[i][j]+B[i][j-1];
                    int a2 = B[x-1][y]-B[x-1][y-1]-B[i][y]+B[i][y-1];
                    int a3 = B[i][y-1]-B[i][j]-B[i-1][y-1]+B[i-1][j];
                    int a4 = B[x][y-1]-B[x][j]-B[x-1][y-1]+B[x-1][j];
                    int a5 = B[x-1][y-1]-B[x-1][j]-B[i][y-1]+B[i][j];
                    int nd = (2*a+2*b-8)-(a1+a2+a3+a4)+a5;
                    // cout<<a1<<" "<<a2<<" "<<a3<<" "<<a4<<" "<<a5<<" "<<nd<<endl;
                    ans = min(ans,nd);
                    if(ans==0){
                        cout<<ans<<endl;
                        return;
                    }
                }
            }
        }
    }
    cout<<ans<<endl;
}

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }

    return 0;
}