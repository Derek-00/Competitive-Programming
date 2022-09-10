/**
 *    author:  wy
 *    created: Sun, 24 Jul 2022 06:04:16 GMT
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "C:\Users\wy\C++\solve\_debug\debug.h"
#else
#define debug(...) 42
#endif

const int N = 11;

int n, m;
bool g[N][N], valid[1 << N];
long long dp[1 << N][N];

int main() {
  scanf("%d %d", &n, &m);
  int a, b;
  while (~scanf("%d %d", &a, &b)) {
    --a; --b;
    g[a][b] = g[b][a] = true;
  }
  const int S = (1 << n) - 1;
  for (int s = 0; s <= S; s++) {
    valid[s] = true;
  }
  for (int s = 0; s <= S; s++) {
    for (int i = n - 1; i >= 0; i--) {
      if (s & (1 << i)) {
        valid[s] &= valid[s ^ (1 << i)];
        for (int j = 0; j < i; j++) {
          if ((s & (1 << j)) && g[i][j]) {
            valid[s] = false;
          }
        }
      }
    }
  }
  int ans = n;
  dp[0][0] = 1;
  for (int c = 1; c <= max(n, m); c++) {
    for (int s = 0; s <= S; s++) {
      dp[s][c] = dp[s][c - 1];
      for (int f = s; f != 0; f = (f - 1) & s) {
        if (valid[f]) {
          dp[s][c] += dp[s ^ f][c - 1];
        }
      }
    }
    if (dp[S][c] != 0) {
      ans = min(ans, c);
    }
  }
  printf("%lld\n%d\n", dp[S][m], ans);
  return 0;
}
