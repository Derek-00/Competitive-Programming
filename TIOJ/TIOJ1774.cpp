/**
 *    author:  willy
 *    created: Fri, 13 Aug 2021 01:30:41 GMT
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<long long> dp(m + 1);
  for (int i = 0; i < n; i++) {
    int h, c;
    cin >> h >> c;
    for (int j = c; j <= m; j++) {
      dp[j] = max(dp[j - c] + h, dp[j]);
    }
  }
  cout << dp[m];
  return 0;
}
