/**
 *    author:  willy
 *    created: Mon, 06 Dec 2021 01:40:25 GMT
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<tuple<int, int, int>> h(n);
  for (int i = 0; i < n; i++) {
    cin >> get<0>(h[i]) >> get<1>(h[i]) >> get<2>(h[i]);
  }
  vector<tuple<int, int, int>> dp(n);
  dp[0] = h[0];
  for (int i = 1; i < n; i++) {
    get<0>(dp[i]) = max(get<0>(dp[i]), max(get<1>(dp[i - 1]), get<2>(dp[i - 1])) + get<0>(h[i]));
    get<1>(dp[i]) = max(get<1>(dp[i]), max(get<0>(dp[i - 1]), get<2>(dp[i - 1])) + get<1>(h[i]));
    get<2>(dp[i]) = max(get<2>(dp[i]), max(get<0>(dp[i - 1]), get<1>(dp[i - 1])) + get<2>(h[i]));
  }
  cout << max({get<0>(dp.back()), get<1>(dp.back()), get<2>(dp.back())}) << '\n';
  return 0;
}
