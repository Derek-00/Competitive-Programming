/**
 *    author:  wy
 *    created: Sun, 25 Dec 2022 13:58:37 GMT
**/
#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;

  vector<vector<int>> a(n, vector<int>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
    }
  }

  const int S = 1 << n;
  vector<i64> f(S);
  for (int s = 0; s < S; s++) {
    for (int x = 0; x < n; x++) {
      if (!(s & (1 << x))) continue;
      for (int y = x + 1; y < n; y++) {
        if (!(s & (1 << y))) continue;
        f[s] += a[x][y];
      }
    }
  }

  vector<i64> dp(S);
  for (int s = 0; s < S; s++) {
    dp[s] = f[s];
    for (int bs = s; bs > 0; bs = (bs - 1) & s) {
      dp[s] = max(dp[s], dp[bs] + dp[s ^ bs]);
    }
  }

  cout << dp[S - 1] << '\n';
  return 0;
}
