#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve(){
    int x,y;
    cin>>x>>y;
    if((x+y)%2==1) cout<<-1<<" "<<-1<<endl;
    else{
        if(x%2==0) cout<<x/2<<" "<<y/2<<endl;
        else{
            cout<<x/2<<" "<<y/2+1<<endl;
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