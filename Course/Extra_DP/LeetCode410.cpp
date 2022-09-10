/**
 *    author:  willy
 *    created: Mon, 15 Nov 2021 03:02:26 GMT
**/
#include <bits/stdc++.h>

using namespace std;

int splitArray(vector<int>& nums, int m) {
  const int n = (int) nums.size();
  vector<int> pref(n + 1);
  for (int i = 1; i <= n; i++) {
    pref[i] = pref[i - 1] + nums[i - 1];
  }
  const int inf = (int) 1e9;
  vector<int> dp(n + 1, inf);
  dp[0] = 0;
  for (int k = 1; k <= m; k++) {
    vector<int> new_dp(n + 1, inf);
    for (int i = 1; i <= n; i++) {
      for (int j = k - 1; j < i; j++) {
        new_dp[i] = min(new_dp[i], max(dp[j], pref[i] - pref[j]));
      }
    }
    swap(dp, new_dp);
  }
  return dp.back();
}
