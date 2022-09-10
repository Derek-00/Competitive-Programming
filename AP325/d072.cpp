/**
 *    author:  wy
 *    created: Wed, 13 Jul 2022 08:34:28 GMT
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "C:\Users\wy\C++\solve\_debug\debug.h"
#else
#define debug(...) 42
#endif

const int N = 100010;

int n, t;
long long a[N][2];
long long dp[N][2];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> t;
  for (int i = 1; i <= n; i++) {
    cin >> a[i][0] >> a[i][1];
  }
  memset(dp, 0x3f3f, sizeof(dp));
  a[0][0] = a[0][1] = t;
  dp[0][0] = dp[0][1] = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= 1; j++) {
      for (int k = 0; k <= 1; k++) {
        long long d = dp[i - 1][k] + abs(a[i][j] - a[i - 1][k]);
        dp[i][j] = min(dp[i][j], d);
      }
    }
  }
  cout << min(dp[n][0], dp[n][1]) << '\n';
  return 0;
}
