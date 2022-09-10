/**
 *    author:  willy
 *    created: Mon, 06 Dec 2021 02:35:59 GMT
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s, t;
  cin >> s >> t;
  const int n = (int) s.size();
  const int m = (int) t.size();
  vector<vector<int>> dp(n, vector<int>(m));
  vector<vector<int>> prv(n, vector<int>(m));
  bool first = false;
  int pos = -1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (s[i] == t[j]) {
        if (!first) {
          pos = i;
          first ^= true;
        }
        dp[i][j] = max(dp[i][j], (i == 0 || j == 0 ? 1 : dp[i - 1][j - 1] + 1));
        prv[i][j] = 1;
      } else {
        if ((i == 0 ? 0 : dp[i - 1][j]) >= (j == 0 ? 0 : dp[i][j - 1])) {
          dp[i][j] = (i == 0 ? 0 : dp[i - 1][j]);
          prv[i][j] = 0;
        } else {
          dp[i][j] = (j == 0 ? 0 : dp[i][j - 1]);
          prv[i][j] = 2;
        }
      }
    }
  }
  int len = dp[n - 1][m - 1];
  string ans = "";
  int x = n - 1;
  int y = m - 1;
  while (len > 0) {
    assert(x >= 0 && y >= 0);
    if (prv[x][y] == 1) {
      --len;
      ans += s[x];
      --x; --y;
    } else {
      if (prv[x][y] == 0) {
        --x;
      } else {
        --y;
      }
    }
  }
  reverse(ans.begin(), ans.end());
  cout << ans << '\n';
  return 0;
}
