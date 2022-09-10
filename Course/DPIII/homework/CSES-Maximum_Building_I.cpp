/**
 *    author:  willy
 *    created: Sun, 10 Oct 2021 10:52:05 GMT
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<vector<char>> g(n, vector<char>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> g[i][j];
    }
  }
  vector<vector<int>> dp(n, vector<int>(m));
  for (int j = 0; j < m; j++) {
    for (int i = 0; i < n; i++) {
      if (g[i][j] == '.') {
        dp[i][j] = (i == 0 ? 1 : dp[i - 1][j] + 1);
      } else {
        dp[i][j] = 0;
      }
    }
  }
  int ans = -1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int h = dp[i][j];
      for (int k = j; k < m; k++) {
        h = min(h, dp[i][k]);
        ans = max(ans, h * (k - j + 1));
      }
    }
  }
  cout << ans << '\n';
  return 0;
}
