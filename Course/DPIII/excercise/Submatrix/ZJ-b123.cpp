/**
 *    author:  willy
 *    created: Wed, 13 Oct 2021 10:49:29 GMT
**/
#include <bits/stdc++.h>

using namespace std;

// problem URL: https://zerojudge.tw/ShowProblem?problemid=b123

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  while (cin >> n >> m) {
    vector<vector<int>> g(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        int x;
        cin >> x;
        g[i][j] = (x == 0 ? 0 : (j == 0 ? 1 : g[i][j - 1] + 1));
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
        R[i] = (stk.empty() ? -1 : stk.back());
        stk.push_back(i);
      }
      for (int i = 0; i < n; i++) {
        ans = max(ans, g[i][j] * (R[i] - L[i] - 1));
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
