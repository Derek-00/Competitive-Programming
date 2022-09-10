/**
 *    author:  willy
 *    created: Wed, 29 Sep 2021 11:26:09 GMT
**/
#include <bits/stdc++.h>

using namespace std;

// problem URL: https://cses.fi/problemset/task/1687/

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  int h = 1;
  while ((1 << h) <= n) {
    ++h;
  }
  vector<vector<int>> pr(n, vector<int>(h, -1));
  for (int i = 1; i < n; i++) {
    cin >> pr[i][0];
    --pr[i][0];
  }
  for (int j = 1; j < h; j++) {
    for (int i = 0; i < n; i++) {
      pr[i][j] = (pr[i][j - 1] == -1 ? -1 : pr[pr[i][j - 1]][j - 1]);
    }
  }
  while (q--) {
    int x, k;
    cin >> x >> k;
    --x;
    int mx = 31 - __builtin_clz(k);
    bool found = true;
    for (int i = 0; i <= mx; i++) {
      if ((1 << i) & k) {
        if (pr[x][i] == -1) {
          cout << -1 << '\n';
          found = false;
          break;
        }
        x = pr[x][i];
      }
    }
    if (found) {
      cout << x + 1 << '\n';
    }
  }
  return 0;
}
