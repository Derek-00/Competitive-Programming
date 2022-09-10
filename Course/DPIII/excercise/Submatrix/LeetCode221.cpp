/**
 *    author:  willy
 *    created: Wed, 13 Oct 2021 11:28:40 GMT
**/
#include <bits/stdc++.h>

using namespace std;

// problem URL: https://leetcode.com/problems/maximal-square/

int maximalSquare(vector<vector<char>>& matrix) {
  const int n = (int) matrix.size();
  const int m = (int) matrix[0].size();
  vector<vector<int>> dp(n + 1, vector<int>(m + 1));
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (matrix[i - 1][j - 1] == '1') {
        dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
        ans = max(ans, dp[i][j]);
      }
    }
  }
  return ans * ans;
}
