/**
 *    author:  willy
 *    created: Mon, 06 Dec 2021 01:47:51 GMT
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, w;
  cin >> n >> w;
  vector<long long> ws(n);
  vector<long long> vs(n);
  for (int i = 0; i < n; i++) {
    cin >> ws[i] >> vs[i];
  }
  const int inf = numeric_limits<int>::max();
  const int MAX = (int) 1e5;
  vector<long long> dp(MAX + 1, inf);
  dp[0] = 0;
  for (int i = 0; i < n; i++) {
    for (int j = MAX; j >= vs[i]; j--) {
      dp[j] = min(dp[j], dp[j - vs[i]] + ws[i]);
    }
  }
  long long ans = 0;
  for (int i = 1; i <= MAX; i++) {
    if (dp[i] <= w) {
      ans = max(ans, (long long) i);
    }
  }
  cout << ans << '\n';
  return 0;
}
