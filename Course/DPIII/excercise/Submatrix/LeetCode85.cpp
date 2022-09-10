/**
 *    author:  willy
 *    created: Wed, 13 Oct 2021 11:01:29 GMT
**/
#include <bits/stdc++.h>

using namespace std;

// problem URL: https://leetcode.com/problems/maximal-rectangle/

int maximalRectangle(vector<vector<char>>& mtx) {
  if (mtx.empty()) {
    return 0;
  }
  const int n = (int) mtx.size();
  const int m = (int) mtx[0].size();
  vector<vector<int>> dp(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      dp[i][j] = (mtx[i][j] == '0' ? 0 : (i == 0 ? 1 : dp[i - 1][j] + 1));
    }
  }
  int mx = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int h = dp[i][j];
      for (int k = j; k < m; k++) {
        h = min(h, dp[i][k]);
        mx = max(mx, h * (k - j + 1));
      }
    }
  }
  return mx;
}
