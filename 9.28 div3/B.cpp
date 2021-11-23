#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct ANS{
    int l,r,d;
    ANS(int l,int r,int d):l(l),r(r),d(d) {}
};

int a[55];

void solve(){
    int n;
    cin>>n;
    vector<pair<int,int>> b(n);
    map<int,int> c;
    for(int i=0;i<n;++i){
        cin>>a[i];
        b[i] = make_pair(a[i],i);
    }
    sort(b.begin(),b.end());
    for(int i=0;i<n;++i){
        c[b[i].second] = i;
    }
    vector<ANS> ans;
    for(int i=0;i<n;++i){
        if(b[i].first != a[i]){
            // cout<<"b[i]:"<<b[i].first<<endl;
            int ind;
            for(int j=i+1;j<n;++j){
                if(a[j]==b[i].first){
                    ind = j;
                    break;
                }
            }
            // int ind = b[i].second;
            int tar = i;
            // cout<<"turn:"<<i<<endl;
            // cout<<"ind:"<<ind<<" tar:"<<tar<<endl;
            if(ind<tar){
                ans.emplace_back(ANS(ind+1,tar+1,1));
                // cout<<ind+1<<" "<<tar+1<<" "<<1<<endl;
                int tmp = a[ind];
                for(int j=ind+1;j<=tar;++j){
                    a[j-1] = a[j];
                }
                a[tar] = tmp;
            }
            else{
                ans.emplace_back(ANS(tar+1,ind+1,ind-tar));
                // cout<<tar+1<<" "<<ind+1<<" "<<ind-tar<<endl;
                int tmp = a[ind];
                for(int j=ind;j>=tar+1;--j) a[j] = a[j-1];
                a[tar] = tmp;
            }
            // cout<<"a: ";
            // for(int i=0;i<n;++i) cout<<a[i]<<(i==n-1 ? '\n' : ' ');
        }
    }
    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();++i){
        cout<<ans[i].l<<" "<<ans[i].r<<" "<<ans[i].d<<endl;
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

/*
1
5
2 5 1 4 3
*/