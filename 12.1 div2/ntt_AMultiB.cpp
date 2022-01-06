#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define fore(i, l, r) for (int i = int(l); i < int(r); ++i)
#define sz(a) int((a).size())
#define endl "\n"

const int MOD = 998244353;

struct Mint
{
  int val;

  bool operator==(const Mint& other)
  {
    return val == other.val;
  }

  Mint operator+(const Mint& other)
  {
    int res = val + other.val;
    while(res >= MOD) res -= MOD;
    while(res < 0) res += MOD;
    return Mint(res);
  }

  Mint operator-(const Mint& other)
  {
    int res = val - other.val;
    while(res >= MOD) res -= MOD;
    while(res < 0) res += MOD;
    return Mint(res);  
  }

  Mint operator*(const Mint& other)
  {
    return Mint((val * 1ll * other.val) % MOD);
  }

  Mint pow(int y)
  {
    Mint z(1);
    Mint x(val);
    while(y > 0)
    {
      if(y % 2 == 1) z = z * x;
      x = x * x;
      y /= 2;
    }
    return z;
  }

  Mint operator/(const Mint& other)
  {
    return Mint(val) * Mint(other.val).pow(MOD - 2);
  }

  Mint() {
      val = 0;
  };
  Mint(int x)
  {
    while(x >= MOD) x -= MOD;
    while(x < 0) x += MOD;
    val = x;
  };
};

ostream& operator<<(ostream& out, const Mint& x)
{
  return out << x.val;
}

// 与MOD的取值有关
const int g = 3;
const int LOGN = 19;

vector<Mint> w[LOGN];
vector<int> rv[LOGN];

void prepare() {
  Mint wb = Mint(g).pow((MOD - 1) / (1 << LOGN));
  forn(st, LOGN - 1) {
    w[st].assign(1 << st, 1);
    Mint bw = wb.pow(1 << (LOGN - st - 1));
    Mint cw = 1;
    forn(k, 1 << st) {
      w[st][k] = cw;
      cw = cw * bw;
    }
  }
  forn(st, LOGN) {
    rv[st].assign(1 << st, 0);
    if (st == 0) {
      rv[st][0] = 0;
      continue;
    }
    int h = (1 << (st - 1));
    forn(k, 1 << st)
      rv[st][k] = (rv[st - 1][k & (h - 1)] << 1) | (k >= h);
  }
}

void ntt(vector<Mint> &a, bool inv) {
  int n = sz(a);
  int ln = __builtin_ctz(n);
  forn(i, n) {
    int ni = rv[ln][i]; // 出现了runtime error 暂时不确定原因
    if (i < ni) swap(a[i], a[ni]);
  }
  forn(st, ln) {
    int len = 1 << st;
    for (int k = 0; k < n; k += (len << 1)) {
      fore(pos, k, k + len){
        Mint l = a[pos];
        Mint r = a[pos + len] * w[st][pos - k];
        a[pos] = l + r;
        a[pos + len] = l - r;
      }
    }
  }
  if (inv) { // 系数表示法
    Mint rn = Mint(n).pow(MOD - 2);
    forn(i, n) a[i] = a[i] * rn;
    reverse(a.begin() + 1, a.end());
  }
}

// 计算多项式相乘
// a: [a0,a1,a2,...] -> a0*x^0 + a1*x^1 + a2*x^2 + ...
vector<Mint> mul(vector<Mint> a, vector<Mint> b) {
  int cnt = 1 << (32 - __builtin_clz(sz(a) + sz(b) - 1)); // 多项式相乘结果的位数
  a.resize(cnt); // 增位
  b.resize(cnt);
  ntt(a, false); // 转化为多项式的点表示法
  ntt(b, false);
  vector<Mint> c(cnt);
  forn(i, cnt) c[i] = a[i] * b[i]; // O(n)得到结果的点表示法
  ntt(c, true); // 转换为系数表示法
  return c;
}

// 清除多项式相乘结果末尾的0
vector<Mint> norm(vector<Mint> a)
{
  while(a.size() > 1 && a.back() == Mint(0))
    a.pop_back();
  return a;
}

int main()
{
  prepare();
  vector<vector<Mint>> cur(2);
  string a,b;
  cin>>a>>b;
  for(int i=sz(a)-1;i>=0;--i) cur[0].push_back(Mint(a[i]-'0')); 
  for(int i=sz(b)-1;i>=0;--i) cur[1].push_back(Mint(b[i]-'0')); 
  vector<Mint> t = norm(mul(cur[0],cur[1]));
  int jw = 0;
  string ans;
  for(int i = 0; i<sz(t) ; i++)
  {
    ans.push_back((t[i].val+jw)%10+'0');
    jw = (t[i].val+jw)/10;
  }
  reverse(ans.begin(),ans.end());
  if(jw>0) cout<<jw; 
  cout<<ans;
  cout<<endl;
}
/*
123456789213123123123123123123123123123122
9876543213122222222222222222222222224444444444444444444444
121932631112635269
*/