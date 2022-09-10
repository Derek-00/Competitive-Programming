/**
 *    author:  wy
 *    created: Mon, 04 Jul 2022 14:15:26 GMT
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
  int n;
  cin >> n;
  vector<vector<int>> a(n, vector<int>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
    }
  }
  vector<bool> y(n);
  map<int, bool> xy;
  map<int, bool> yx;
  int ans = (int) -1e9;
  function<void(int, int)> Solve = [&](int x, int score) {
    if (x >= n) {
      ans = max(ans, score);
      return;
    }
    Solve(x + 1, score);
    for (int j = 0; j < n; j++) {
      if (!y[j] && !xy[x + j] && !yx[x - j]) {
        y[j] = xy[x + j] = yx[x - j] = true;
        Solve(x + 1, score + a[x][j]);
        y[j] = xy[x + j] = yx[x - j] = false;
      }
    }
  };
  Solve(0, 0);
  cout << ans << '\n';
  return 0;
}
