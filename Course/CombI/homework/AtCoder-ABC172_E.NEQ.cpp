/**
 *    author:  willy
 *    created: Sat, 27 Nov 2021 14:36:46 GMT
**/
#include <bits/stdc++.h>

using namespace std;

#define int long long

const int md = (int) 1e9 + 7;

void extgcd(int a, int b, int& x, int& y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return;
  }
  int nx, ny;
  int p = a / b;
  extgcd(b, a - p * b, nx, ny);
  x = ny;
  y = nx - p * ny;
}

int inverse(int a, int m = md) {
  int x, y;
  extgcd(a, m, x, y);
  return x;
}

inline int Mul(int x, int y) {
  return (long long) x * y % md;
}

inline int Add(int x, int y) {
  x += y - md;
  x += md & (x >> 31);
  return x;
}

vector<int> fact(1, 1);
vector<int> inv_fact(1, 1);

int C(int n, int k) {
  if (k < 0 || k > n) {
    return 0;
  }
  while ((int) fact.size() <= n) {
    fact.push_back(Mul(fact.back(), (int) fact.size()));
    inv_fact.push_back((inverse(fact.back()) + md) % md);
  }
  return Mul(Mul(fact[n], inv_fact[k]), inv_fact[n - k]);
}

int P(int n, int k) {
  if (k < 0 || k > n) {
    return 0;
  }
  while ((int) fact.size() <= n) {
    fact.push_back(Mul(fact.back(), (int) fact.size()));
    inv_fact.push_back((inverse(fact.back()) + md) % md);
  }
  return Mul(fact[n], inv_fact[n - k]);
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  int ans = P(m, n);
  for (int i = 1; i <= n; i++) {
    int res = Mul(C(n, i), P(m - i, n - i)) * (i & 1 ? -1 : 1);
    ans += res;
    ans = (ans + md) % md;
  }
  ans = Mul(ans, P(m, n));
  cout << (ans + md) % md << '\n';
  return 0;
}
