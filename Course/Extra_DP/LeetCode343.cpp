/**
 *    author:  willy
 *    created: Tue, 12 Oct 2021 10:14:13 GMT
**/
#include <bits/stdc++.h>

using namespace std;

// problem URL: https://leetcode.com/problems/integer-break/

int integerBreak(int n) {
  vector<int> dp(n + 1);
  dp[2] = 1;
  for (int i = 3; i <= n; i++) {
    for (int j = 1; j * 2 <= i; j++) {
      dp[i] = max(dp[i], max(dp[j], j) * max(dp[i - j], i - j));
    }
  }
  return dp[n];
}
