#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int f(int a,int m){
    if(a == m) return 0;
    else return m+1-a;
}

void solve(){
    int a,b,c;
    cin>>a>>b>>c;
    int m = max(a,max(b,c));
    int t = (a==m ? 1 : 0) + (b==m ? 1 : 0) + (c==m ? 1 : 0);
    if(t==1){
    cout<<f(a,m)<<" ";
    cout<<f(b,m)<<" ";
    cout<<f(c,m)<<endl;
    }
    else{
        cout<<m+1-a<<" "<<m+1-b<<" "<<m+1-c<<endl;
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