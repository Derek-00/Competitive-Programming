/**
 *    author:  willy
 *    created: Mon, 08 Nov 2021 02:09:47 GMT
**/
#include <bits/stdc++.h>

using namespace std;

int maximalRectangle(vector<vector<char>>& mtx) {
  if (mtx.empty()) {
    return 0;
  }
  const int n = (int) mtx.size();
  const int m = (int) mtx[0].size();
  vector<vector<int>> g(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      g[i][j] = (mtx[i][j] == '0' ? 0 : (j == 0 ? 1 : g[i][j - 1] + 1));
    }
  }
  int ans = 0;
  for (int j = 0; j < m; j++) {
    vector<int> stk;
    vector<int> L(n);
    for (int i = 0; i < n; i++) {
      while (!stk.empty() && g[stk.back()][j] >= g[i][j]) {
        stk.pop_back();
      }
      L[i] = (stk.empty() ? -1 : stk.back());
      stk.push_back(i);
    }
    stk.clear();
    vector<int> R(n);
    for (int i = n - 1; i >= 0; i--) {
      while (!stk.empty() && g[stk.back()][j] >= g[i][j]) {
        stk.pop_back();
      }
      R[i] = (stk.empty() ? n : stk.back());
      stk.push_back(i);
    }
    for (int i = 0; i < n; i++) {
      ans = max(ans, g[i][j] * (R[i] - L[i] - 1));
    }
  }
  return ans;
}
