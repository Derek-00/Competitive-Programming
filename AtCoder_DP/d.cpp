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
  vector<int> ws(n);
  vector<long long> vs(n);
  for (int i = 0; i < n; i++) {
    cin >> ws[i] >> vs[i];
  }
  vector<long long> dp(w + 1);
  for (int i = 0; i < n; i++) {
    for (int j = w; j >= ws[i]; j--) {
      dp[j] = max(dp[j], (long long) dp[j - ws[i]] + vs[i]);
    }
  }
  cout << dp[w] << '\n';
  return 0;
}
