#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 20010;
int f[N];

void solve(){
    int n;
    cin>>n;
    int s = 0;
    vector<int> a(n);
    for(int i=0;i<n;++i) cin>>a[i],s += a[i];
    if(f[s]){
        cout<<n<<endl;
        for(int i=1;i<=n;++i){
            cout<<i<<(i==n ? '\n' : ' ');
        }
        return;
    }
    for(int i=0;i<n;++i){
        if(f[s-a[i]]){
            cout<<n-1<<endl;
            for(int j=0;j<n;++j){
                if(j!=i) cout<<j+1<<" ";
            }
            cout<<endl;
            return;
        }
    }
    for(int i=0;i<n;++i){
        for(int j=i+1;j<n;++j){
            if(f[s-a[i]-a[j]]){
                cout<<n-2<<endl;
                for(int k=0;k<n;++k){
                    if(k!=i && k!=j) cout<<k+1<<" ";
                }
                cout<<endl;
                return;
            }
        }
    }
    for(int i=0;i<n;++i){
        for(int j=i+1;j<n;++j){
            for(int k=j+1;k<n;++k){
                cout<<n-3<<endl;
                for(int p=0;p<n;++p){
                    if(p!=i && p!=j && p!=k) cout<<p+1<<" ";
                }
                cout<<endl;
                return;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    for(int i=2;i<N;++i){
        if(f[i]==0){
            for(int j=i*2;j<N;j+=i){
                f[j] = 1;
            }
        }
    }
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }

    return 0;
}