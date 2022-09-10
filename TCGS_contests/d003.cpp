/**
 *    author:  willy
 *    created: Sat, 06 Nov 2021 08:22:23 GMT
**/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string a, b;
  while (cin >> a >> b) {
    int n = (int) a.size();
    int m = (int) b.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    vector<vector<int>> prv(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        if (a[i - 1] == b[j - 1]) {
          dp[i][j] = dp[i - 1][j - 1] + 1;
          prv[i][j] = 0;
        } else {
          if (dp[i - 1][j] < dp[i][j - 1]) {
            dp[i][j] = dp[i][j - 1];
            prv[i][j] = 2; // left
          } else {
            dp[i][j] = dp[i - 1][j];
            prv[i][j] = 1; // up
          }
        }
      }
    }
    cout << a << " " << b << " = ";
    if (dp[n][m] == 0) {
      cout << 0 << '\n';
      continue;
    }
    int len = dp[n][m];
    int i = n, j = m;
    string res = "";
    while (len > 0) {
      if (prv[i][j] == 0) {
        res += a[i - 1];
        --len; --i; --j;
      } else {
        if (prv[i][j] == 1) { // from upside
          --i;
        } else { // from leftside
          --j;
        }
      }
    }
    reverse(res.begin(), res.end());
    cout << res << '\n';
  }
  return 0;
}
