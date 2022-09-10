/**
 *    author:  wy
 *    created: Tue, 05 Jul 2022 12:13:20 GMT
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "C:\Users\wy\C++\solve\_debug\debug.h"
#else
#define debug(...) 42
#endif

int pref[300010][55];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int g;
  cin >> g;
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> pref[j][i];
      pref[j][i] += pref[j][i - 1];
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= i; j++) {
      set<int> s = {0};
      int sum = 0;
      for (int k = 1; k <= m; k++) {
        sum += pref[k][i] - pref[k][j - 1];
        auto it = s.lower_bound(sum - g);
        if (it != s.end()) {
          assert(sum - *it <= g);
          ans = max(ans, sum - *it);
        }
        s.insert(sum);
      }
    }
  }
  cout << ans << '\n';
  return 0;
}
