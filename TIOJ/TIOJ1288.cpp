/**
 *    author:  willy
 *    created: Sat, 25 Sep 2021 14:11:24 GMT
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<vector<int>> a(n);
  for (int i = 0; i < n; i++) {
    a[i].resize(i + 1);
    for (int j = 0; j <= i; j++) {
      cin >> a[i][j];
    }
  }
  vector<vector<int>> dp(n);
  for (int i = 0; i < n; i++) {
    dp[i].resize(i + 1);
  }
  for (int i = n - 1; i >= 0; i--) {
    for (int j = 0; j <= i; j++) {
      if (i < n - 1) {
        dp[i][j] = a[i][j] + max(dp[i + 1][j], dp[i + 1][j + 1]);
      } else {
        dp[i][j] = a[i][j];
      }
    }
  }
  cout << dp[0][0] << '\n';
  return 0;
}
