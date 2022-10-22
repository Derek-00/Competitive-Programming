/**
 *    author:  wy
 *    created: Sat, 22 Oct 2022 15:13:53 GMT
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "C:\Users\wy\C++\solve\_debug\debug.h"
#else
#define debug(...) 42
#endif

const int N = 500;

int a[N], pref[N];
long long dp[N][N];

void setIO() {
  freopen("snakes.in", "r", stdin);
  freopen("snakes.out", "w", stdout);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  setIO();
  int n, k;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    pref[i] = pref[i - 1] + a[i];
  }
  memset(dp, 0x3f, sizeof(dp));
  long long mx = 0;
  for (int i = 1; i <= n; i++) {
    mx = max(mx, (long long) a[i]);
    dp[i][0] = mx * i - pref[i];
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= k; j++) {
      long long mx = 0;
      for (int l = i; l > 0; l--) {
        mx = max(mx, (long long) a[l]);
        long long wst = (i - l + 1) * mx - (pref[i] - pref[l - 1]);
        dp[i][j] = min(dp[i][j], dp[l - 1][j - 1] + wst);
      }
    }
  }
  cout << dp[n][k] << '\n';
  return 0;
}
