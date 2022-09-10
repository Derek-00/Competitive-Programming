/**
 *    author:  willy
 *    created: Tue, 12 Oct 2021 13:37:19 GMT
**/
#include <bits/stdc++.h>

using namespace std;

// problem URL: https://leetcode.com/problems/palindrome-partitioning-ii/

int minCut(string s) {
  const int n = (int) s.size();
  vector<vector<bool>> ok(n, vector<bool>(n, false));
  vector<int> dp(n, n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= i; j++) {
      if (s[i] == s[j] && (i - j <= 2 || ok[j + 1][i - 1])) {
        ok[j][i] = true;
        dp[i] = (j == 0 ? 0 : min(dp[i], dp[j - 1] + 1));
      }
    }
  }
  return dp[n - 1];
}
