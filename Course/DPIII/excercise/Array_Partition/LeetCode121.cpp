/**
 *    author:  willy
 *    created: Sun, 10 Oct 2021 13:17:39 GMT
**/
#include <bits/stdc++.h>

using namespace std;

// problem URL: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

int maxProfit(vector<int>& prices) {
  int mn = (int) 1e4;
  int ans = -1;
  for (int i = 0; i < (int) prices.size(); i++) {
    mn = min(mn, prices[i]);
    ans = max(ans, prices[i] - mn);
  }
  return ans;
}
