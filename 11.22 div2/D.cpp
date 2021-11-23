#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve(){
    ll a,b,x;
    cin>>a>>b>>x;
    while(x<=max(a,b)){
        if(a<b) swap(a,b);
        if(b==0) break;
        if(x%b==a%b){
            cout<<"YES"<<endl;
            return;
        }
        cout<<a<<" "<<b<<endl;
        a = a%b;
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