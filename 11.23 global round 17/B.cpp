#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve(vector<int> aa){
    int n = 5;
    vector<int> a(n+1),pos[n+1];
    map<int,int> mp;
    for(int i=1;i<=n;++i){
        a[i] = aa[i-1];
        mp[a[i]]++;
        pos[a[i]].push_back(i);
    }
    if(mp.size()==1){
        cout<<"YES"<<endl;
        return;
    }
    int xx = mp.begin()->first;
    vector<int> p;
    for(int i=1;i<=n;++i){
        if(a[i]!=xx) p.push_back(a[i]);
    }
    bool ok = true;
    for(int j=0;j<p.size();++j){
        if(p[j]!=p[p.size()-1-j]){
            ok = false;
            break;
        }
    }
    if(ok){
        cout<<"YES"<<endl;
        return;
    }
    int cnt = 0;
    for(auto t: mp){
        int x = t.first, y = t.second;
        if(x==xx) continue;
        vector<int> pp(pos[xx]);
        for(int i=0;i<pos[x].size();++i) pp.push_back(pos[x][i]);
        sort(pp.begin(),pp.end());
        ok = true;
        for(int j=0;j<pp.size();++j){
            if(a[pp[j]]!=a[pp[pp.size()-1-j]]){
                ok = false;
                break;
            }
        }
        if(!ok){
            cnt++;
        }
    }
    if(cnt>=2) cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
    // if(!ok){x
    //     cout<<"NO"<<endl;
    //     return;
    // }
    // vector<int> p1,p2;
    // for(int i=1;i<=n;++i){
    //     if(a[i]!=x) p1.push_back(a[i]);
    //     if(a[i]!=y) p2.push_back(a[i]);
    // }
    // ok = true;
    // for(int j=0;j<p1.size();++j){
    //     if(p1[j]!=p1[p1.size()-1-j]){
    //         ok = false;
    //         break;
    //     }
    // }   
    // if(ok){
    //     cout<<"YES"<<endl;
    //     return;
    // }
    // ok = true;
    // for(int j=0;j<p2.size();++j){
    //     if(p2[j]!=p2[p2.size()-1-j]){
    //         ok = false;
    //         break;
    //     }
    // }   
    // if(ok){
    //     cout<<"YES"<<endl;
    //     return;
    // }
    // cout<<"NO"<<endl;
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