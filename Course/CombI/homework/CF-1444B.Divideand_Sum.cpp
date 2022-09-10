/**
 *    author:  willy
 *    created: Sun, 28 Nov 2021 13:22:13 GMT
**/
#include <bits/stdc++.h>

using namespace std;

#define int long long

const int md = 998244353;

inline void add(int &a, int b) {
  a += b;
  if (a >= md) a -= md;
}

inline int mul(int a, int b) {
  return (int) ((long long) a * b % md);
}

inline int inv(int a) {
  a %= md;
  if (a < 0) a += md;
  int b = md, u = 0, v = 1;
  while (a) {
    int t = b / a;
    b -= t * a; swap(a, b);
    u -= t * v; swap(u, v);
  }
  assert(b == 1);
  if (u < 0) u += md;
  return u;
}

vector<int> fact(1, 1);
vector<int> inv_fact(1, 1);

int C(int n, int k) {
  if (k < 0 || k > n) {
    return 0;
  }
  while ((int) fact.size() <= n) {
    fact.push_back(mul(fact.back(), (int) fact.size()));
    inv_fact.push_back(inv(fact.back()));
  }
  return mul(mul(fact[n], inv_fact[n - k]), inv_fact[k]);
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n + n);
  for (int i = 0; i < n + n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  int ans = 0;
  for (int i = 0; i < n; i++) {
    add(ans, a[i + n] - a[i]);
  }
  cout << mul(C(n + n, n), ans) << '\n';
  return 0;
}
