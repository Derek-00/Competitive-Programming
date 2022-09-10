/**
 *    author:  wy
 *    created: Tue, 05 Jul 2022 06:45:02 GMT
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "C:\Users\wy\C++\solve\_debug\debug.h"
#else
#define debug(...) 42
#endif

long long p;

void Solve(int id, long long sum, vector<long long> a, set<long long>& s) {
  if (sum > p) {
    return;
  }
  if (id >= (int) a.size()) {
    s.insert(sum);
    return;
  }
  Solve(id + 1, sum + a[id], a, s);
  Solve(id + 1, sum, a, s);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n >> p;
  int na = n >> 1;
  vector<long long> a(na);
  for (int i = 0; i < na; i++) {
    cin >> a[i];
  }
  int nb = n - na;
  vector<long long> b(nb);
  for (int i = 0; i < nb; i++) {
    cin >> b[i];
  }
  set<long long> sa;
  Solve(0, 0LL, a, sa);
  set<long long> sb;
  Solve(0, 0LL, b, sb);
  long long ans = 0;
  for (auto e : sa) {
    long long mx = p - e;
    auto it = sb.lower_bound(mx);
    if (it != sb.end()) {
      if (e + *it > p) {
        if (it != sb.begin()) {
          it = prev(it);
          assert(e + *it < p);
          ans = max(ans, e + *it);
        }
      } else {
        assert(e + *it == p);
        ans = e + *it;
        break;
      }
    }
  }
  cout << ans << '\n';
  debug(clock());
  return 0;
}
