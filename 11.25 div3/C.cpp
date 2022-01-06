#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(auto& x: a) cin>>x;
    deque<int> t1,t2;
    for(int i=0,j=n-1;i<=j;){
        if(a[i]>=a[j]){
            t1.push_front(a[i]);
            i++;
        } 
        else{
            t1.push_back(a[j]);
            j--;
        }
    }
    vector<int> b(t1.begin(),t1.end());
    int i,j;
    for(i=0,j=n-1;i<j;){
        if(b[i]<=b[j]){
            t2.push_front(b[i]);
            i++;
        }
        else{
            t2.push_back(b[j]);
            j--;
        }
    }
    t2.push_front(b[i]);
    bool ok = false;
    ok |= (a == vector<int>(t2.begin(),t2.end()));
    t2.pop_front();
    t2.push_back(b[i]);
    ok |= (a == vector<int>(t2.begin(),t2.end()));
    if(ok){
        for(auto& x: b) cout<<x<<" ";
        cout<<endl;
    }
    else cout<<-1<<endl;
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