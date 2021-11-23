#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve(){
    int n;
    string s;
    cin>>n>>s;
    vector<int> a(n+1,0),b(n+1,0),c(n+1,0),v;
    for(int i=1;i<=n;++i){
        a[i]=a[i-1],b[i]=b[i-1],c[i]=c[i-1];
        if(s[i-1]=='a'){
            a[i]++;
            v.push_back(i);
        }
        else if(s[i-1]=='b') b[i]++;
        else c[i]++;
    }
    if(a[n]<=1) cout<<-1<<endl;
    else{
        int ans = 1e8;
        for(int i=1;i<v.size();++i){
            int l = v[i-1], r = v[i];
            int aa = a[r]-a[l-1], bb = b[r]-b[l-1], cc = c[r]-c[l-1];
            if(aa>bb && aa>cc) ans = min(ans,r-l+1);
        }
        for(int i=2;i<v.size();++i){
            int l = v[i-2], r = v[i];
            int aa = a[r]-a[l-1], bb = b[r]-b[l-1], cc = c[r]-c[l-1];
            if(aa>bb && aa>cc) ans = min(ans,r-l+1);            
        }
        cout<<(ans==1e8 ? -1 : ans)<<endl;
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