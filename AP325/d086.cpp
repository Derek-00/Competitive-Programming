/**
 *    author:  wy
 *    created: Fri, 15 Jul 2022 14:50:41 GMT
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "C:\Users\wy\C++\solve\_debug\debug.h"
#else
#define debug(...) 42
#endif

const int N = 210;

int n;
long long p[N];
long long dp[N][N];

long long Solve(int l, int r) {
  if (dp[l][r] >= 0) {
    return dp[l][r];
  }
  long long mn = (long long) 9e18;
  for (int k = l + 1; k < r; k++) {
    long long cost = Solve(l, k) + Solve(k, r);
    cost += p[l] * p[k] * p[r];
    mn = min(mn, cost);
  }
  return dp[l][r] = mn;
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i <= n; i++) {
    scanf("%lld", &p[i]);
  }
  memset(dp, -1, sizeof(dp));
  for (int i = 0; i < n; i++) {
    dp[i][i + 1] = 0;
  }
  printf("%lld\n", Solve(0, n));
  return 0;
}
