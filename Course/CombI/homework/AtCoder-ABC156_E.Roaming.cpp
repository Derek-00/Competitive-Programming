/**
 *    author:  willy
 *    created: Sun, 28 Nov 2021 12:52:42 GMT
**/
#include <bits/stdc++.h>

using namespace std;

const int md = (int) 1e9 + 7;

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
  return mul(mul(fact[n], inv_fact[k]), inv_fact[n - k]);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  int ans = 0;
  for (int i = 0; i <= k; i++) {
    add(ans, mul(C(n, i), C(n - 1, i)));
  }
  cout << ans << '\n';
  return 0;
}
