/**
 *    author:  willy
 *    created: Sat, 27 Nov 2021 13:09:52 GMT
**/
#include <bits/stdc++.h>

using namespace std;

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
  string s;
  getline(cin, s);
  vector<int> cnt(26);
  for (auto& c : s) {
    cnt[(int) (c - 'a')]++;
  }
  int ans = 1;
  int n = (int) s.size();
  for (int i = 0; i < 26; i++) {
    if (cnt[i] == 0) {
      continue;
    }
    ans = Mul(ans, C(n, cnt[i]));
    n -= cnt[i];
  }
  cout << ans << '\n';
  return 0;
}
