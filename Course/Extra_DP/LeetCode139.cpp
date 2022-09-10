/**
 *    author:  willy
 *    created: Mon, 11 Oct 2021 15:32:02 GMT
**/
#include <bits/stdc++.h>

using namespace std;

// problem URL: https://leetcode.com/problems/word-break/

bool wordBreak(string s, vector<string>& wordDict) {
  vector<vector<string>> ws(26);
  for (auto& w : wordDict) {
    int id = (int) (w[0] - 'a');
    ws[id].push_back(w);
  }
  const int n = (int) s.size();
  vector<bool> dp(n + 1, false);
  dp[0] = true;
  for (int i = 0; i < n; i++) {
    int id = (int) (s[i] - 'a');
    for (auto& w : ws[id]) {
      if (dp[i] && s.substr(i, (int) w.size()) == w) {
        dp[i + (int) w.size()] = true;
      }
    }
  }
  return dp.back();
}
