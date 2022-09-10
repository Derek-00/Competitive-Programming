/**
 *    author:  wy
 *    created: Sat, 16 Jul 2022 14:34:46 GMT
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "C:\Users\wy\C++\solve\_debug\debug.h"
#else
#define debug(...) 42
#endif

const int N = (int) 1e6;

int n;
int w[N], dp[N];

int Solve(int x) {
  if (dp[x] >= 0) {
    return dp[x];
  }
  int mx = 0;
  for (int i = 0; i < n; i++) {
    if (x & (1 << i)) {
      mx = max(mx, Solve(x ^ (1 << i)));
    }
  }
  return dp[x] = mx + w[x];
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < (1 << n); i++) {
    scanf("%d", &w[i]);
  }
  memset(dp, -1, sizeof(dp));
  dp[0] = w[0];
  printf("%d\n", Solve((1 << n) - 1));
  return 0;
}
