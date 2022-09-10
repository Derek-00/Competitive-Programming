/**
 *    author:  wy
 *    created: Fri, 15 Jul 2022 14:36:04 GMT
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "C:\Users\wy\C++\solve\_debug\debug.h"
#else
#define debug(...) 42
#endif

const int N = 210;

int n, l;
int p[N], dp[N][N];

int Solve(int l, int r) {
  if (dp[l][r] >= 0) {
    return dp[l][r];
  }
  int mn = (int) 1e9;
  for (int i = l + 1; i < r; i++) {
    mn = min(mn, Solve(l, i) + Solve(i, r));
  }
  return dp[l][r] = mn + (p[r] - p[l]);
}

int main() {
  scanf("%d %d", &n, &l);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &p[i]);
  }
  p[0] = 0;
  p[n + 1] = l;
  for (int i = 0; i <= n + 1; i++) {
    for (int j = i + 1; j <= n + 1; j++) {
      dp[i][j] = -1;
    }
  }
  for (int i = 0; i <= n + 1; i++) {
    dp[i][i + 1] = 0;
  }
  printf("%d\n", Solve(0, n + 1));
  return 0;
}
