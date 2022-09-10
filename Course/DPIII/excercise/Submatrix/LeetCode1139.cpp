/**
 *    author:  willy
 *    created: Thu, 14 Oct 2021 11:22:54 GMT
**/
#include <bits/stdc++.h>

using namespace std;

// problem URL: https://leetcode.com/problems/largest-1-bordered-square/

int largest1BorderedSquare(vector<vector<int>>& grid) {
  const int n = (int) grid.size();
  const int m = (int) grid[0].size();
  vector<vector<int>> row(n, vector<int>(m));
  vector<vector<int>> col(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (grid[i][j] == 1) {
        row[i][j] = (j == 0 ? 1 : row[i][j - 1] + 1);
        col[i][j] = (i == 0 ? 1 : col[i - 1][j] + 1);
      }
    }
  }
  int mx = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (grid[i][j] == 0) {
        continue;
      }
      int edge = min(row[i][j], col[i][j]);
      for (int e = edge - 1; e >= 0; e--) {
        if (col[i][j - e] >= e + 1 && row[i - e][j] >= e + 1) {
          mx = max(mx, (e + 1) * (e + 1));
          break;
        }
      }
    }
  }
  return mx;
}
