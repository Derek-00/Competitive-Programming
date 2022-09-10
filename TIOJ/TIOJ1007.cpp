/**
 *    author:  willy
 *    created: Sat, 14 Aug 2021 08:18:47 GMT
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 100;

long long dp[N] = {};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  dp[0] = 1;
  for (int i = 1; i <= n + 1; i++) {
    dp[i] = dp[i - 1] << 1;
  }
  dp[n + 1]--;
  for (int i = n + 2; i <= m; i++) {
    dp[i] = (dp[i - 1] << 1) - dp[i - n - 2];
  }
  cout << dp[m] << '\n';
  return 0;
}
