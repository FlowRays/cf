/*
1.容斥原理：
    至少违反k([0,n-1])条规则的涂色方式的集合 的 并集的元素个数
    从而用容斥原理求解 多个集合的并集个数
2.违反k条规则的方案数：
    由于违反k条规则的选择中并不是任意的选C(n-1,k)种，因为不同的规则可能相互排斥，如一个结点的多个子结点中只能选一个规则违反
    考虑dp[i][j]: 前i个结点中刚好违反j条规则(选中j条边，保证每个结点的子边最多选1条)的方案数
        d[i]: i结点的子结点数(即子边数)
    dp[i][j] = dp[i-1][j]+dp[i-1][j-1]*d[i]
    边界: dp[i][0] = 1 dp[0][j] = 0 (dp[0][0] = 1)
    ans: dp[n][k]
    note: 这n个结点指的是d[i]>0的结点个数，选择方式与这n个结点的排布方式无关，故而可以用fft优化
3.分治+ntt优化:
    以样例1为例, 要求的dp[n][k]实际就是 (1+d[1]*x)*(1+d[2]*x) = (1+x)*(1+3x) = 3x^2+4x+1 的系数
    将这n个多项式相乘，可以每次两两相乘，此为logn
    然后用ntt logn计算
    故最终复杂度为O(n(logn)^2)
tip:
    fft: 快速傅里叶变换
    ntt: 快速数论变换
*/

#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define fore(i, l, r) for (int i = int(l); i < int(r); ++i)
#define sz(a) int((a).size())

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
    int ni = rv[ln][i];
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
// 以上均为ntt模板所需

const int N = 250043;
vector<int> G[N];
int d[N]; // i结点的子结点个数

Mint fact[N * 2];
Mint rev[N * 2];

void dfs(int x, int p)
{
  if(p != x) d[p]++;
  for(auto y : G[x]) if(y != p) dfs(y, x);
}

Mint C(int n, int k)
{
  return fact[n] * rev[k] * rev[n - k];
}

int main()
{
  prepare();
  fact[0] = Mint(1);
  for(int i = 1; i < N * 2; i++) fact[i] = fact[i - 1] * i;
  for(int i = 0; i < N * 2; i++) rev[i] = Mint(1) / fact[i];
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n - 1; i++)
  {
    int x, y;
    scanf("%d %d", &x, &y);
    --x;
    --y;
    G[x].push_back(y);
    G[y].push_back(x);  
  }
  dfs(0, 0);    // 获取每个结点的子结点数
  vector<vector<Mint>> cur;
  for(int i = 0; i < n; i++)
    if(d[i] > 0)
      cur.push_back(vector<Mint>({Mint(1), Mint(d[i])})); // 多项式 1+d[i]*x
  while(cur.size() > 1)
  {
    vector<vector<Mint>> ncur;
    for(int i = 0; i + 1 < cur.size(); i += 2) // 分治
      ncur.push_back(norm(mul(cur[i], cur[i + 1])));
    if(cur.size() % 2 == 1) ncur.push_back(cur.back());
    cur = ncur;  
  }
  Mint ans = 0;
  for(int i = 0; i < cur[0].size(); i++)
  {
    if(i % 2 == 0) ans = ans + cur[0][i] * fact[n - i];
    else ans = ans - cur[0][i] * fact[n - i];
  }
  cout << ans << endl;
}