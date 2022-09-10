/**
 *    author:  willy
 *    created: Sun, 28 Nov 2021 08:20:14 GMT
**/
#include <bits/stdc++.h>

using namespace std;

const int md = (int) 1e9 + 7;

inline int mulmod(int u, int v) {
  return (long long) u * v % md;
}

void extgcd(int a, int b, int& x, int& y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return;
  }
  int nx, ny;
  int t = a / b;
  extgcd(b, a - t * b, nx, ny);
  x = ny;
  y = nx - t * ny;
}

int inverse(int a, int m = md) {
  int x, y;
  extgcd(a, m, x, y);
  return (x + md) % md;
}

vector<int> fact(1, 1);
vector<int> inv_fact(1, 1);

int C(int n, int k) {
  if (k < 0 || k > n) {
    return 0;
  }
  while ((int) fact.size() <= n) {
    fact.push_back(mulmod(fact.back(), (int) fact.size()));
    inv_fact.push_back(inverse(fact.back()));
  }
  return mulmod(mulmod(fact[n], inv_fact[k]), inv_fact[n - k]);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  string s;
  cin >> s;
  if (n & 1) {
    cout << 0 << '\n';
    return 0;
  }
  n >>= 1;
  int x = 0, y = 0;
  int c = 0;
  for (int i = 0; i < (int) s.size(); i++) {
    if (s[i] == '(') {
      x++;
      c++;
    }
    if (s[i] == ')') {
      if (c <= 0) {
        cout << 0 << '\n';
        return 0;
      }
      y++;
      c--;
    }
  }
  if (x > n) {
    cout << 0 << '\n';
    return 0;
  }
  int total = n * 2 - x - y;
  cout << (C(total, n - x) - C(total, n - x - 1) + md) % md << '\n';
  return 0;
}
