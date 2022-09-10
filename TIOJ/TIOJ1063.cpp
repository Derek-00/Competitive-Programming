/**
 *    author:  willy
 *    created: Thu, 26 Aug 2021 11:42:11 GMT
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    int cnt = 0;
    for (int j = 0; j < m; j++) {
      int x;
      cin >> x;
      if (x == 1) {
        ++cnt;
      } else {
        cnt = 0;
      }
      g[i][j] = cnt;
    }
  }
  int best = 0;
  for (int j = 0; j < m; j++) {
    vector<int> L(n);
    {
      vector<int> stk;
      for (int i = 0; i < n; i++) {
        while (!stk.empty() && g[stk.back()][j] >= g[i][j]) {
          stk.pop_back();
        }
        L[i] = (stk.empty() ? -1 : stk.back());
        stk.push_back(i);
      }
    }
    vector<int> R(n);
    {
      vector<int> stk;
      for (int i = n - 1; i >= 0; i--) {
        while (!stk.empty() && g[stk.back()][j] >= g[i][j]) {
          stk.pop_back();
        }
        R[i] = (stk.empty() ? n : stk.back());
        stk.push_back(i);
      }
    }
    for (int i = 0; i < n; i++) {
      best = max(best, g[i][j] * (R[i] - L[i] - 1));
    }
  }
  cout << best << '\n';
  return 0;
}
