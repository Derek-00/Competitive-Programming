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
  vector<double> cur(n);
  vector<double> prv(n);
  for (int i = 0; i < n; i++) {
    prv[i] = pref[i] / (i + 1);
  }
  for (int kk = 1; kk < k; kk++) {
    for (int i = kk; i < n; i++) {
      for (int j = 0; j < i; j++) {
        cur[i] = max(cur[i], prv[j] + (pref[i] - pref[j]) / (i - j)); // pref[j] = pref[j + 1 - 1]
      }
    }
    swap(prv, cur);
  }
  return prv[n - 1];
}
