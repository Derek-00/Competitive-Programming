/**
 *    author:  willy
 *    created: Mon, 06 Dec 2021 01:30:18 GMT
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<int> h(n);
  for (int i = 0; i < n; i++) {
    cin >> h[i];
  }
  const int inf = (int) 1e9;
  vector<int> dp(n, inf);
  dp[0] = 0;
  for (int i = 0; i < n; i++) {
    for (int j = max(i - k, 0); j < i; j++) {
      dp[i] = min(dp[i], dp[j] + abs(h[i] - h[j]));
    }
  }
  cout << dp[n - 1] << '\n';
  return 0;
}
