/**
 *    author:  willy
 *    created: Wed, 13 Oct 2021 13:11:03 GMT
**/
#include <bits/stdc++.h>

using namespace std;

// problem URL: https://leetcode.com/problems/largest-plus-sign/

int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
  vector<vector<bool>> g(n, vector<bool>(n, true));
  for (int i = 0; i < (int) mines.size(); i++) {
    g[mines[i][0]][mines[i][1]] = false;
  }
  vector<vector<int>> up(n, vector<int>(n));
  vector<vector<int>> down(n, vector<int>(n));
  vector<vector<int>> left(n, vector<int>(n));
  vector<vector<int>> right(n, vector<int>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (g[i][j]) {
        up[i][j] = (i == 0 ? 1 : up[i - 1][j] + 1);
        left[i][j] = (j == 0 ? 1 : left[i][j - 1] + 1);
      }
    }
  }
  for (int i = n - 1; i >= 0; i--) {
    for (int j = n - 1; j >= 0; j--) {
      if (g[i][j]) {
        down[i][j] = (i == n - 1 ? 1 : down[i + 1][j] + 1);
        right[i][j] = (j == n - 1 ? 1 : right[i][j + 1] + 1);
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (g[i][j]) {
        int edge = min({up[i][j], down[i][j], left[i][j], right[i][j]});
        ans = max(ans, edge);
      }
    }
  }
  return ans;
}
