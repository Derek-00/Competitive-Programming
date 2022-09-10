/**
 *    author:  wy
 *    created: Mon, 04 Jul 2022 14:54:03 GMT
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "C:\Users\wy\C++\solve\_debug\debug.h"
#else
#define debug(...) 42
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> a(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }
  int ans = (int) 1e9;
  function<void(int, int, int, int, int)> Solve = [&](int xa, int xb, int ya, int yb, int cost) {
    if (xa == xb || ya == yb) {
      ans = min(ans, cost);
      return;
    }
    {
      int up = 0;
      for (int j = ya; j <= yb; j++) {
        up += a[xa][j];
      }
      up = min(yb - ya  + 1 - up, up);
      Solve(xa + 1, xb, ya, yb, cost + up);
    }
    {
      int down = 0;
      for (int j = ya; j <= yb; j++) {
        down += a[xb][j];
      }
      down = min(yb - ya + 1 - down, down);
      Solve(xa, xb - 1, ya, yb, cost + down);
    }
    {
      int left = 0;
      for (int i = xa; i <= xb; i++) {
        left += a[i][ya];
      }
      left = min(xb - xa + 1 - left, left);
      Solve(xa, xb, ya + 1, yb, cost + left);
    }
    {
      int right = 0;
      for (int i = xa; i <= xb; i++) {
        right += a[i][yb];
      }
      right = min(xb - xa + 1 - right, right);
      Solve(xa, xb, ya, yb - 1, cost + right);
    }
  };
  Solve(0, n - 1, 0, m - 1, 0);
  cout << ans << '\n';
  return 0;
}
