/**
 *    author:  willy
 *    created: Fri, 29 Oct 2021 11:45:50 GMT
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<vector<int>> dp(n + 4, vector<int>(n + 4));
  int sum = 0;
  for (int i = 2; i < n + 2; i++) {
    cin >> dp[i][i];
    sum += dp[i][i];
  }
  for (int i = 2; i < n + 2; i++) {
    for (int j = i - 1; j >= 2; j--) {
      dp[j][i] = max(dp[j][j] + min(dp[j + 1][i - 1], dp[j + 2][i]), dp[i][i] + min(dp[j][i - 2], dp[j + 1][i - 1]));
    }
  }
  cout << dp[2][n + 1] << " " << sum - dp[2][n + 1] << '\n';
  return 0;
}
