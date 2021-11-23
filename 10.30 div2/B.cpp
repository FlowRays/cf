#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve(){
    int n;
    cin>>n;
    vector<int> a(n),b(n);
    map<int,int> mp;
    bool ok = true;
    for(int i=0;i<n;++i){
        cin>>a[i];
        b[i] = a[i];
        mp[a[i]]++;
        if(mp[a[i]]>=2) ok = false;
    }
    sort(b.begin(),b.end());
    bool ok2 = true;
    for(int i=0;i<n;++i){
        if(a[i]!=b[i]){
            ok2 = false;
            break;
        }
    }
    if(n%2==1 && (ok && ok2)){
        cout<<"NO"<<endl;
    }
    else{
        cout<<"YES"<<endl;
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