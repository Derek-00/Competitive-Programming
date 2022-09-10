/**
 *    author:  willy
 *    created: Sat, 09 Oct 2021 08:16:07 GMT
**/
#include <bits/stdc++.h>

using namespace std;

// problem URL: https://leetcode.com/problems/largest-divisible-subset/

vector<int> largestDivisibleSubset(vector<int>& nums) {
  sort(nums.begin(), nums.end());
  int n = (int) nums.size();
  vector<int> dp(n, 1);
  vector<int> pr(n, -1);
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < i; j++) {
      if (nums[i] % nums[j] == 0) {
        if (pr[i] == -1) {
          dp[i] = dp[j] + 1;
          pr[i] = j;
        } else {
          if (dp[i] < dp[j] + 1) {
            dp[i] = dp[j] + 1;
            pr[i] = j;
          }
        }
      }
    }
  }
  int mx = -1;
  int id = -1;
  for (int i = 0; i < n; i++) {
    if (mx < dp[i]) {
      mx = dp[i];
      id = i;
    }
  }
  vector<int> ret;
  while (pr[id] >= 0) {
    ret.push_back(nums[id]);
    id = pr[id];
  }
  ret.push_back(nums[id]);
  return ret;
}
