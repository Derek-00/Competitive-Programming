/**
 *    author:  willy
 *    created: Mon, 11 Oct 2021 09:46:29 GMT
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  while (cin >> n >> m && n) {
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> a[i][j];
      }
    }
    vector<vector<int>> dp(n, vector<int>(m));
    for (int j = 0; j < m; j++) {
      for (int i = 0; i < n; i++) {
        if (a[i][j] == 0) {
          dp[i][j] = (i == 0 ? 1 : dp[i - 1][j] + 1);
        }
      }
    }
    int ans = 0;
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
  }
  return 0;
}
