/**
 *    author:  willy
 *    created: Fri, 14 Jan 2022 16:17:29 GMT
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
  const int cc = 5;
  vector<int> dp(cc, 1);
  for (int i = 1; i < n; i++) {
    vector<int> new_dp(cc);
    new_dp[0] = dp[0];
    for (int j = 1; j < cc; j++) {
      new_dp[j] = new_dp[j - 1] + dp[j];
    }
    swap(dp, new_dp);
  }
  cout << accumulate(dp.begin(), dp.end(), 0) << '\n';
  return 0;
}
