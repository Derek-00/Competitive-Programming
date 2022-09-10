/**
 *    author:  willy
 *    created: Tue, 08 Feb 2022 07:29:23 GMT
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "C:\Users\wy\C++\solve\_debug\debug.h"
#else
#define debug(...) 42
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<long long> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<long long> pref(n);
  pref[0] = a[0];
  for (int i = 1; i < n; i++) {
    pref[i] = pref[i - 1] + a[i];
  }
  vector<vector<long long>> dp(n, vector<long long>(n, 9e18));
  for (int i = 0; i < n; i++) {
    dp[i][i] = 0;
  }
  for (int l = n - 1; l >= 0; l--) {
    for (int r = l; r < n; r++) {
      long long sum = pref[r] - (l == 0 ? 0 : pref[l - 1]);
      for (int k = l; k < r; k++) {
        dp[l][r] = min(dp[l][r], dp[l][k] + dp[k + 1][r] + sum);
      }
    }
  }
  cout << dp[0][n - 1] << '\n';
  return 0;
}
