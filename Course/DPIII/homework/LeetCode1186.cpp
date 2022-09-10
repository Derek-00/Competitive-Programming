/**
 *    author:  willy
 *    created: Mon, 11 Oct 2021 12:36:41 GMT
**/
#include <bits/stdc++.h>

using namespace std;

// problem URL: https://leetcode.com/problems/maximum-subarray-sum-with-one-deletion/

bool all_negative(const vector<int>& a) {
  for (auto& v : a) {
    if (v >= 0) {
      return false;
    }
  }
  return true;
}

int maximumSum(vector<int>& a) {
  if (all_negative(a)) {
    return *max_element(a.begin(), a.end());
  }
  int n = (int) a.size();
  auto Get = [&]() {
    vector<int> dp(n);
    int total = max(0, a[0]);
    dp[0] = max(0, a[0]);
    for (int i = 1; i < n; i++) {
      total += a[i];
      total = max(total, 0);
      dp[i] = total;
    }
    return dp;
  };
  auto dp = Get();
  reverse(a.begin(), a.end());
  auto new_dp = Get();
  reverse(new_dp.begin(), new_dp.end());
  int ans = *max_element(dp.begin(), dp.end());
  for (int i = 1; i < n - 1; i++) {
    ans = max(ans, dp[i - 1] + new_dp[i + 1]);
  }
  return ans;
}
