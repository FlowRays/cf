#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define fore(i, l, r) for (int i = int(l); i <= int(r); ++i)
#define sz(a) int((a).size())
#define endl "\n"
#define pii pair<int,int>

using namespace std;
using ll = long long;

// bit template from jiangly
template <typename T>
struct Fenwick {
    const int n;
    std::vector<T> a;
    Fenwick(int n) : n(n), a(n) {}
    void add(int x, T v) {
        for (int i = x + 1; i <= n; i += i & -i) {
            a[i - 1] += v;
        }
    }
    T sum(int x) {
        T ans = 0;
        for (int i = x; i > 0; i -= i & -i) {
            ans += a[i - 1];
        }
        return ans;
    }
    T rangeSum(int l, int r) {
        return sum(r) - sum(l);
    }
};

void solve(){
    int n;
    cin>>n;
    Fenwick<ll> fen(n);
    string s,t;
    cin>>s>>t;
    ll ans = 1e18;
    ll cost = 0;
    vector<int> p[26];
    forn(i,n){
        p[s[i]-'a'].push_back(i);
    }
    vector<int> cnt(26,0);
    // use fenwick tree to calc the thift during swaps
    // then we does not need to swap actually
    // 一种是像这样维护thift量有多少 参考: https://codeforces.com/contest/1616/submission/141260604
    // 另一种是像tourist一样直接维护swap后的实际坐标，add的时候-1
    // 原理是看了comment https://codeforces.com/blog/entry/98501?#comment-873249 懂的
    forn(i,n){
        // find a character among s[i,n-1] that smaller than t[i]
        forn(j,t[i]-'a'){
            if(cnt[j]<p[j].size()){
                ll old_idx = p[j][cnt[j]]; // closest char satisfies smaller
                ll thift = fen.rangeSum(old_idx,n); // how many swaps made result in thifts relatively
                ll new_idx = old_idx+thift; // real idx in need
                ans = min(ans,cost+new_idx-i); // update the ans: cost(make equal prefix) + swaps(make smaller char)
            }
        }
        if(cnt[t[i]-'a'] >= p[t[i]-'a'].size()) break; // not found -> break
        // calc the cost to keep the prefix s[0,i] equal to t[0,i]
        cost += p[t[i]-'a'][cnt[t[i]-'a']] + fen.rangeSum(p[t[i]-'a'][cnt[t[i]-'a']],n) - i;
        fen.add(p[t[i]-'a'][cnt[t[i]-'a']], 1); // move it to the front, so it causes 1 thift
        // cout<<" "<<i<<" "<<cost<<" "<<s<<endl;
        cnt[t[i]-'a']++;
    }
    cout<<(ans==1e18 ? -1ll : ans)<<endl;
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