/**
 *    author:  wy
 *    created: Sun, 17 Jul 2022 10:40:54 GMT
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "C:\Users\wy\C++\solve\_debug\debug.h"
#else
#define debug(...) 42
#endif

const int N = 17;
const int B = 1 << 17;
const int inf = (int) 1e9;

int n, m;
int dist[N][N], dp[N][B];

int Solve(int s, int bits) {
  if (dp[s][bits] >= 0) {
    return dp[s][bits];
  }
  int mn = inf;
  for (int b = 0; b < n; b++) {
    if (b != s && (bits & (1 << b))) {
      mn = min(mn, Solve(b, bits ^ (1 << s)) + dist[b][s]);
    }
  }
  return dp[s][bits] = mn;
}

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%d", &dist[i][j]);
    }
  }
  int ans = inf;
  for (int e = 0; e < n; e++) {
    int mn = inf;
    memset(dp, -1, sizeof(dp));
    dp[0][1] = 0;
    ans = min(ans, Solve(e, (1 << n) - 1) + dist[0][e]);
  }
  printf("%d\n", ans);
  return 0;
}
