/**
 *    author:  willy
 *    created: Sat, 27 Nov 2021 10:37:02 GMT
**/
#include <bits/stdc++.h>

using namespace std;

const int md = (int) 1e9 + 7;

int inverse(int a, int m = md) {
  int u = 0, v = 1;
  while (a != 0) {
    int t = m / a;
    m -= t * a; swap(a, m);
    u -= t * v; swap(u, v);
  }
  assert(m == 1);
  return u;
}

int Mul(int x, int y) {
  return (long long) x * y % md;
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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int a, b;
    cin >> a >> b;
    cout << C(a, b) << '\n';
  }
  return 0;
}
