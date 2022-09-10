/**
 *    author:  willy
 *    created: Sat, 09 Oct 2021 12:43:22 GMT
**/
#include <bits/stdc++.h>

using namespace std;

// problem URL: https://leetcode.com/problems/longest-palindromic-subsequence/

int longestPalindromeSubseq(string s) {
  int n = (int) s.size();
  vector<vector<int>> dp(n, vector<int>(n));
  for (int l = n - 1; l >= 0; l--) {
    for (int r = l; r < n; r++) {
      if (l == r) {
        dp[l][r] = 1;
      } else {
        if (s[l] == s[r]) {
          dp[l][r] = dp[l + 1][r - 1] + 2;
        } else {
          dp[l][r] = max(dp[l + 1][r], dp[l][r - 1]);
        }
      }
    }
  }
  return dp[0][n - 1];
}
