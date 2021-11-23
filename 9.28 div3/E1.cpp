#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(auto& x: v) cin>>x;
    deque<int> dq;
    dq.push_back(v[0]);
    for(int i=1;i<v.size();++i){
        if(v[i]<dq.front()) dq.push_front(v[i]);
        else dq.push_back(v[i]);
    }
    for(int i=0;i<v.size();++i){
        cout<<dq.front()<<(i==v.size()-1 ? '\n' : ' ');
        dq.pop_front();
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