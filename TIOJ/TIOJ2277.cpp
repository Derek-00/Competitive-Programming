/**
 *    author:  wy
 *    created: Fri, 16 Sep 2022 15:37:07 GMT
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
  int n, m;
  cin >> n >> m;
  vector<vector<long long>> a(n, vector<long long>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }
  const long long inf = (long long) 9e18;
  int l, r, u, d;
  long long ans = -inf;
  for (int i = 0; i < n; i++) {
    long long mn = 0;
    int mn_id = 0;
    long long pref = 0;
    for (int j = 0; j < m; j++) {
      pref += a[i][j];
      if (ans < pref - mn) {
        u = d = i;
        l = mn_id;
        r = j;
        ans = pref - mn;
      }
      if (pref < mn) {
        mn = pref;
        mn_id = j + 1;
      }
      if (mn > 0) {
        mn = mn_id = 0;
      }
    }
  }
  for (int j = 0; j < m; j++) {
    long long mn = 0;
    int mn_id = 0;
    long long pref = 0;
    for (int i = 0; i < n; i++) {
      pref += a[i][j];
      if (ans < pref - mn) {
        l = r = j;
        u = mn_id;
        d = i;
        ans = pref - mn;
      }
      if (pref < mn) {
        mn = pref;
        mn_id = i + 1;
      }
      if (mn > 0) {
        mn = mn_id = 0;
      }
    }
  }
  debug(l, r, u, d, ans);
  cout << ans << '\n';
  for (int i = 0; i < l; i++) {
    cout << 'L';
  }
  for (int i = m - 1; i > r; i--) {
    cout << 'R';
  }
  for (int i = 0; i < u; i++) {
    cout << 'U';
  }
  for (int i = n - 1; i > d; i--) {
    cout << 'D';
  }
  cout << (l == r ? 'L' : 'U') << '\n';
  return 0;
}
