#include <bits/stdc++.h>

using namespace std;
using ll = long long;

// 首先求出取值的上下界，得到答案(条件判断要仔细耐心)
// 根据答案去构造配凑
// 并不难，花了过多时间
void solve(){
    ll n,m;
    cin>>n>>m;
    vector<ll> a(n),b(n),c(n);
    ll A1 = 0, A2 = 0, A = 0;
    ll T = 0;
    for(int i=0;i<n;++i){
        cin>>a[i]>>b[i];
        T += a[i]-b[i];
        A1 += max(0ll,m-b[i]);
        A2 += min(m,a[i]);
    }
    T += n*m;
    if(T-2*A2>=0) A = A2;
    else if(T-2*A1<=0) A = A1;
    else A = T/2;
    cout<<abs(T-2*A)<<endl;
    ll t = A-A1;
    for(int i=0;i<n;++i){
        ll a_min = max(0ll,m-b[i]), a_max =min(m,a[i]);
        if(t==0) cout<<a_min<<" "<<m-a_min<<endl;
        else if(t>=a_max-a_min){
            cout<<a_max<<" "<<m-a_max<<endl;
            t -= a_max-a_min;
        }
        else{
            cout<<a_min+t<<" "<<m-(a_min+t)<<endl;
            t = 0;
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