#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve(){
    ll x,n;
    cin>>x>>n;
    if(n==0){
        cout<<x<<endl;
        return;
    }
    ll t = (n-1)/4;
    ll p = t*4;
    ll ans;
    if(abs(x)%2==1){
        ans = x+1+4*t;
    }
    else{
        ans = x-1-4*t;
    }
    p+=2;
    // cout<<p<<" "<<ans<<endl;
    while(p<=n){
        if(abs(ans)%2==1) ans+=p;
        else ans-=p;
        // cout<<ans<<endl;
        p++;
    }
    cout<<ans<<endl;
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