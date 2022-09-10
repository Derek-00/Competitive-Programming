/**
 *    author:  willy
 *    created: Tue, 08 Feb 2022 07:56:25 GMT
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
  vector<long long> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  vector<vector<long long>> dp(n + 2, vector<long long>(n + 1));
  for (int l = n; l > 0; l--) {
    for (int r = l; r <= n; r++) {
      dp[l][r] = max(a[l] - dp[l + 1][r], a[r] - dp[l][r - 1]);
    }
  }
  cout << dp[1][n] << '\n';
  return 0;
}
