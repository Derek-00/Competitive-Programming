/**
 *    author:  wy
 *    created: Sat, 22 Oct 2022 08:20:43 GMT
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
  freopen("time.in", "r", stdin);
  freopen("time.out", "w", stdout);
  int n, m, c;
  cin >> n >> m >> c;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<vector<int>> g(n);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    --a; --b;
    g[a].push_back(b);
  }
  const int T = 1000;
  vector<int> dp(n, -1);
  dp[0] = 0;
  int ans = 0;
  for (int t = 1; t < T; t++) {
    vector<int> new_dp(n, -1);
    for (int u = 0; u < n; u++) {
      if (dp[u] == -1) {
        continue;
      }
      for (int v : g[u]) {
        new_dp[v] = max(new_dp[v], dp[u] + a[v]);
      }
    }
    dp.swap(new_dp);
    ans = max(ans, dp[0] - (c * t * t));
  }
  cout << ans << '\n';
  return 0;
}
