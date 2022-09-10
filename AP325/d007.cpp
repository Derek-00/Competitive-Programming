/**
 *    author:  wy
 *    created: Mon, 04 Jul 2022 09:47:22 GMT
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "C:\Users\wy\C++\solve\_debug\debug.h"
#else
#define debug(...) 42
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  long long p;
  cin >> n >> p;
  vector<long long> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  long long ans = -1;
  function<void(int, long long)> Solve = [&](int id, long long sum) {
    if (sum > p) {
      return;
    }
    if (id >= n) {
      if (sum <= p) {
        ans = max(ans, sum);
      }
      return;
    }
    Solve(id + 1, sum + a[id]);
    Solve(id + 1, sum);
  };
  Solve(0, 0LL);
  cout << ans << '\n';
  return 0;
}
