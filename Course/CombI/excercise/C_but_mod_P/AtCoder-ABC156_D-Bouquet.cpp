/**
 *    author:  willy
 *    created: Sun, 28 Nov 2021 07:32:24 GMT
**/
#include <bits/stdc++.h>

using namespace std;

const int md = (int) 1e9 + 7;

inline int mulmod(int x, int y) {
  return (long long) x * y % md;
}

int power(int x, int k) {
  int res = 1;
  while (k > 0) {
    if (k & 1) res = mulmod(res, x);
    x = mulmod(x, x);
    k >>= 1;
  }
  return res;
}

int extgcd(int a, int b, int& x, int& y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  int nx, ny;
  int t = a / b;
  int g = extgcd(b, a - t * b, nx, ny);
  x = ny;
  y = nx - t * ny;
  return g;
}

int inverse(int a, int m = md) {
  int x, y;
  int g = extgcd(a, m, x, y);
  if (g != 1) {
    cout << 0 << '\n';
    exit(0);
  }
  return x;
}

vector<int> fact(1, 1);
vector<int> inv_fact(1, 1);

int C(int n, int k) {
  if (k < 0 || k > n) {
    return 0;
  }
  k = min(k, n - k);
  while ((int) fact.size() <= k) {
    fact.push_back(mulmod(fact.back(), (int) fact.size()));
    inv_fact.push_back(inverse(fact.back()));
  }
  int res = 1;
  for (int i = n - k + 1; i <= n; i++) {
    res = mulmod(res, i);
  }
  return mulmod(res, inv_fact[k]);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, a, b;
  cin >> n >> a >> b;
  long long ans = power(2, n) - 1 - C(n, a) - C(n, b);
  cout << (ans + md) % md << '\n';
  return 0;
}
