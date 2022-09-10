/**
 *    author:  wy
 *    created: Sun, 17 Jul 2022 03:35:59 GMT
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "C:\Users\wy\C++\solve\_debug\debug.h"
#else
#define debug(...) 42
#endif

const int N = 30;

int n, m;
int a[N][N];
int dp[N][N][N][N];

int Solve(int u, int d, int l, int r) {
  if (dp[u][d][l][r] >= 0) {
    return dp[u][d][l][r];
  }
  int mn = (int) 1e9;
  { // top-row
    int cnt = 0;
    for (int k = l; k <= r; k++) {
      cnt += a[u][k];
    }
    cnt = min(cnt, (r - l + 1) - cnt);
    mn = min(mn, Solve(u + 1, d, l, r) + cnt);
  }
  { // bottom-row
    int cnt = 0;
    for (int k = l; k <= r; k++) {
      cnt += a[d][k];
    }
    cnt = min(cnt, (r - l + 1) - cnt);
    mn = min(mn, Solve(u, d - 1, l, r) + cnt);
  }
  { // left-column
    int cnt = 0;
    for (int k = u; k <= d; k++) {
      cnt += a[k][l];
    }
    cnt = min(cnt, (d - u + 1) - cnt);
    mn = min(mn, Solve(u, d, l + 1, r) + cnt);
  }
  { // right-column
    int cnt = 0;
    for (int k = u; k <= d; k++) {
      cnt += a[k][r];
    }
    cnt = min(cnt, (d - u + 1) - cnt);
    mn = min(mn, Solve(u, d, l, r - 1) + cnt);
  }
  return dp[u][d][l][r] = mn;
}

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      scanf("%d", &a[i][j]);
    }
  }
  for (int u = 0; u < n; u++) {
    for (int d = u; d < n; d++) {
      for (int l = 0; l < m; l++) {
        for (int r = l; r < m; r++) {
          dp[u][d][l][r] = (u == d || l == r ? 0 : -1);
        }
      }
    }
  }
  printf("%d\n", Solve(0, n - 1, 0, m - 1));
  return 0;
}
