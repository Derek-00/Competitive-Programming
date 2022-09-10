/**
 *    author:  wy
 *    created: Thu, 14 Jul 2022 05:49:06 GMT
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "C:\Users\wy\C++\solve\_debug\debug.h"
#else
#define debug(...) 42
#endif

const int N = 123;
const int W = 100010;

int n, t;
int w[N], p[N];
int dp[N][W];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> t;
  for (int i = 1; i <= n; i++) {
    cin >> w[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> p[i];
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < w[i]; j++) {
      dp[i][j] = dp[i - 1][j];
    }
    for (int j = w[i]; j <= t; j++) {
      dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + p[i]);
    }
  }
  cout << dp[n][t] << '\n';
  return 0;
}
