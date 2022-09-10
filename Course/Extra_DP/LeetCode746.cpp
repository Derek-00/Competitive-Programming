/**
 *    author:  willy
 *    created: Mon, 15 Nov 2021 12:24:50 GMT
**/
#include <bits/stdc++.h>

using namespace std;

int minCostClimbingStairs(vector<int>& cost) {
  const int n = (int) cost.size();
  vector<int> dp(n + 1, (int) 1e9);
  dp[0] = dp[1] = 0;
  for (int i = 0; i < n; i++) {
    dp[i + 1] = min(dp[i + 1], dp[i] + cost[i]);
    if (i + 2 <= n) {
      dp[i + 2] = min(dp[i + 2], dp[i] + cost[i]);
    }
  }
  return dp[n];
}
