#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve(){
    int n,a,b;
    cin>>n>>a>>b;
    if(a<b){
        if(!((b-1)>=n/2 && a<=n/2) ){
            cout<<-1<<endl;
            
            return;
        }
        else{
            int cnt = 1;
            map<int,int> mp;
            cout<<a<<" ";
            mp[a]++;
            for(int i=n;i>=a;--i){
                if(i!=b){
                    cout<<i<<" ";
                    cnt++;
                    mp[i]++;
                }
                if(cnt==n/2) break;
            }
            for(int i=1;i<=n;++i)
            {
                if(mp[i]==0){
                    cout<<i<<" ";
                }
            }
            cout<<endl;
        }
    }
    else{
        if( !(b>=n/2 && (n-(a-1))>=n/2) ){
            cout<<-1<<endl;
            return;
        }
        else{
            for(int i=a;i<=n;++i)
                cout<<i<<" ";
            for(int i=1;i<=b;++i)
                cout<<i<<" ";
            cout<<endl;
        }
    }

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