/**
 *    author:  willy
 *    created: Mon, 06 Dec 2021 15:20:52 GMT
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<double> p(n + 1);
  p[0] = 1.0;
  for (int i = 1; i <= n; i++) {
    cin >> p[i];
  }
  vector<vector<double>> dp(n + 1, vector<double>(n + 1));
  dp[1][0] = 1 - p[1];
  dp[1][1] = p[1];
  for (int i = 2; i <= n; i++) {
    for (int j = 0; j <= i; j++) {
      dp[i][j] = (j == 0 ? 0 : dp[i - 1][j - 1] * p[i]) + dp[i - 1][j] * (1 - p[i]);
    }
  }
  double ans = 0;
  for (int i = n; i > n / 2; i--) {
    ans += dp[n][i];
  }
  cout << fixed << setprecision(17) << ans << '\n';
  return 0;
}
