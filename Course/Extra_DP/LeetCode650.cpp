/**
 *    author:  willy
 *    created: Mon, 15 Nov 2021 11:48:49 GMT
**/
#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int minSteps(int n) {
    const int MAX = 1001;
    vector<int> dp(MAX, (int) 1e9);
    dp[1] = 0;
    dp[2] = 2;
    for (int i = 3; i <= n; i++) {
      for (int j = 2; j < i; j++) {
        if (i % j == 0) {
          dp[i] = min(dp[i], (i / j) - 1 + 1 + dp[j]);
        }
      }
      dp[i] = min(dp[i], i);
    }
    return dp[n];
  }
};
