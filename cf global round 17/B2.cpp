/**
 *    author:  tourist
 *    created: 23.11.2021 17:37:21       
**/
#include <bits/stdc++.h>

using namespace std;


bool solve(vector<int> aa){
    int n = 5;
    vector<int> a(n+1),pos[n+1];
    map<int,int> mp;
    for(int i=1;i<=n;++i){
        a[i] = aa[i-1];
        mp[a[i]]++;
        pos[a[i]].push_back(i);
    }
    if(mp.size()==1){
        return true;
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
        return true;
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
    if(cnt>=2) return false;
    return true;
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
  int tt = 5*5*5*5*5;
//   cin >> tt;
for(int i=1;i<=5;++i)
    for(int j=1;j<=5;++j)
        for(int k=1;k<=5;++k)
            for(int aa=1;aa<=5;++aa)
                for(int b=1;b<=5;++b){
                    int n=5;
    vector<int> a(5);
                    a[0]=i,a[1]=j,a[2]=k,a[3]=aa,a[4]=b;
                bool ok = false;
                if (a == vector<int>(a.rbegin(), a.rend())) {
                // cout << "YES" << "\n";
                ok = true;
                // continue;
                }
                
                auto Test = [&](int x) {

                vector<int> b;
                for (int i = 0; i < n; i++) {
                    if (a[i] != x) {
                    b.push_back(a[i]);
                    }
                }
                ok |= (b == vector<int>(b.rbegin(), b.rend()));
                };
                if(!ok){
                for (int i = 0; i < n; i++) {
                if (a[i] != a[n - 1 - i]) {
                    Test(a[i]);
                    Test(a[n - 1 - i]);
                    break;
                }
                }}
                // cout << (ok ? "YES" : "NO") << '\n';
                bool ok2 = solve(a);
                if(ok!=ok2) cout<<i<<" "<<j<<" "<<k<<" "<<aa<<" "<<b<<endl;

                }
    
  return 0;
}
