#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve(){
    ll k,x;
    cin>>k>>x;
    ll tot = (k+1)*k/2ll+(k-1)*k/2ll;
    if(x>=tot) cout<<2*k-1<<endl;
    else if(x>=(k+1)*k/2ll){
        ll m = (-1+sqrt(1ll-4ll*(2*x-2*tot)))/2;
        cout<<2*k-1-m<<endl;
    }
    else{
        ll m = ceil((-1+sqrt(1ll+8*x))/2);
        cout<<m<<endl;
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