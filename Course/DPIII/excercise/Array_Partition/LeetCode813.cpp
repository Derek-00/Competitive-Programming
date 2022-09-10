/**
 *    author:  willy
 *    created: Tue, 12 Oct 2021 15:36:27 GMT
**/
#include <bits/stdc++.h>

using namespace std;

// problem URL: https://leetcode.com/problems/largest-sum-of-averages/

double largestSumOfAverages(vector<int>& nums, int k) {
  const int n = (int) nums.size();
  vector<double> pref(n);
  pref[0] = nums[0];
  for (int i = 1; i < n; i++) {
    pref[i] = pref[i - 1] + nums[i];
  }
  vector<vector<double>> dp(k, vector<double>(n));
  for (int i = 0; i < n; i++) {
    dp[0][i] = pref[i] / (i + 1);
  }
  for (int kk = 1; kk < k; kk++) {
    for (int i = kk; i < n; i++) {
      for (int j = 0; j < i; j++) {
        dp[kk][i] = max(dp[kk][i], dp[kk - 1][j] + (pref[i] - pref[j + 1 - 1]) / (i - j));
      }
    }
  }
  return dp[k - 1][n - 1];
}
