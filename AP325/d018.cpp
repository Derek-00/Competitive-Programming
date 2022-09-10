/**
 *    author:  wy
 *    created: Tue, 05 Jul 2022 06:31:13 GMT
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "C:\Users\wy\C++\solve\_debug\debug.h"
#else
#define debug(...) 42
#endif

int p;

void Solve(int id, long long prod, vector<long long> a, map<long long, int>& mp) {
  if (id >= (int) a.size()) {
    mp[prod] += 1;
    return;
  }
  Solve(id + 1, (prod * a[id]) % p, a, mp);
  Solve(id + 1, prod, a, mp);
}

long long power(long long x, int k) {
  long long ans = 1;
  while (k > 0) {
    if (k & 1) {
      ans = (ans * x) % p;
    }
    x = (x * x) % p;
    k >>= 1;
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n >> p;
  int na = n / 2;
  vector<long long> a(na);
  for (int i = 0; i < na; i++) {
    cin >> a[i];
  }
  int nb = n - na;
  vector<long long> b(nb);
  for (int i = 0; i < nb; i++) {
    cin >> b[i];
  }
  map<long long, int> ma;
  Solve(0, 1, a, ma);
  map<long long, int> mb;
  Solve(0, 1, b, mb);
  ma[1] -= 1;
  mb[1] -= 1;
  int ans = ma[1] + mb[1];
  for (auto ea : ma) {
    long long md = power(ea.first, p - 2);
    auto it = mb.find(md);
    if (it != mb.end()) {
      ans = (ans + ea.second * it->second) % p;
    }
  }
  cout << ans << '\n';
  return 0;
}
