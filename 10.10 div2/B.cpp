#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int a[1010][5];

void solve(){
    int n;
    cin>>n;
    for(int i=0;i<n;++i){
        for(int j=0;j<5;++j){
            cin>>a[i][j];
        }
    }
    int cnt[5] = {0};
    int cc[5][5] = {0};
    for(int j=0;j<5;++j){
        for(int i=0;i<n;++i){
            cnt[j] += a[i][j];
        }
    }
    // cout<<cnt[0]<<" "<<cnt[1]<<endl;
    bool ok = false;
    int tar = n/2;
    for(int i=0;i<5;++i){
        for(int j=i+1;j<5;++j){
            if(cnt[i]<tar || cnt[j]<tar){
                continue;
            }
            for(int ii=0;ii<n;++ii){
                if(a[ii][i] && a[ii][j]) cc[i][j]++;
            }
            int x = cnt[i];
            int y = cnt[j];
            int z = cc[i][j],tmp = z;
            if(x-z<n/2){
                // x += (n/2-x);
                tmp -= (n/2-(x-z));
                if(y-z<n/2){
                    tmp -= (n/2-(y-z));
                    if(tmp>=0){
                        cout<<"YES"<<endl;
                        return;
                    }
                }
                else{
                    cout<<"YES"<<endl;
                    return;     
                }
            }
            else{
                if(y-z<n/2){
                    tmp -= (n/2-(y-z));
                    if(tmp>=0){
                        cout<<"YES"<<endl;
                        return;
                    }
                }
                else{
                    // cout<<i<<" "<<j<<endl;
                    cout<<"YES"<<endl;
                    return;     
                }
            }
        }
    }
    cout<<"NO"<<endl;
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