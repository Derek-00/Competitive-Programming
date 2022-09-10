/**
 *    author:  willy
 *    created: Sun, 10 Oct 2021 13:28:48 GMT
**/
#include <bits/stdc++.h>

using namespace std;

// problem URL: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/

int maxProfit(vector<int>& prices) {
  int n = (int) prices.size();
  vector<int> dp(n);
  dp[0] = 0;
  int mn = prices[0];
  for (int i = 1; i < n; i++) {
    mn = min(mn, prices[i]);
    dp[i] = max(dp[i - 1], prices[i] - mn);
  }
  vector<int> ndp(n);
  ndp[n - 1] = 0;
  int mx = prices[n - 1];
  for (int i = n - 2; i >= 0; i--) {
    mx = max(mx, prices[i]);
    ndp[i] = min(ndp[i + 1], prices[i] - mx);
  }
  int ans = -1;
  for (int i = 0; i < n - 1; i++) {
    ans = max(ans, dp[i] - ndp[i + 1]);
  }
  ans = max(ans, dp[n - 1]);
  return ans;
}
