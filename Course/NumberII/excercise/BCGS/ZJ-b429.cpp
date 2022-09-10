/**
 *    author:  willy
 *    created: Tue, 02 Nov 2021 13:29:06 GMT
**/
#include <bits/stdc++.h>

using namespace std;

pair<int, int> extgcd(int a, int b) {
  if (b == 0) {
    return make_pair(1, 0);
  }
  auto p = extgcd(b, a % b);
  int x = p.second;
  int y = p.first - a / b * p.second;
  return make_pair(x, y);
}

int mod_inv(int a, int m) {
  auto p = extgcd(a, m);
  int x = p.first;
  return (x % m + m) % m;
}

int mul(int a, int b, int md) {
  int res = 0;
  while (b > 0) {
    if (b & 1) {
      res += a;
      if (res >= md) {
        res -= md;
      }
    }
    a <<= 1;
    b >>= 1;
    if (a >= md) {
      a -= md;
    }
  }
  return res;
}

int power(int x, int k, int md) {
  int res = 1;
  while (k > 0) {
    if (k & 1) {
      res = mul(res, x, md);
    }
    x = mul(x, x, md);
    k >>= 1;
  }
  return res;
}

int BCGS(int a, int b, int n) {
  unordered_map<int, int> r;
  const int BLOCK = (int) sqrt(n) + 1;
  {
    int t = 1;
    for (int i = 0; i <= BLOCK; i++) {
      if (r.count(t) == 0) {
        r[t] = i;
      }
      t = mul(t, a, n);
    }
  }
  int na = power(a, BLOCK, n);
  int naiv = mod_inv(na, n);
  {
    int t = b;
    for (int i = 0; i <= BLOCK; i++) {
      if (r.count(t) == 1) {
        return i * BLOCK + r[t];
      }
      t = mul(t, naiv, n);
    }
  }
  return -1;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int a, b, n;
  while (cin >> a >> b >> n) {
    int ans = BCGS(a, b, n);
    if (ans == -1) {
      cout << "NOT FOUND" << '\n';
    } else {
      cout << ans << '\n';
    }
  }
  return 0;
}
