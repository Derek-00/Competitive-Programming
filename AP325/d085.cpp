/**
 *    author:  wy
 *    created: Thu, 14 Jul 2022 15:31:01 GMT
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "C:\Users\wy\C++\solve\_debug\debug.h"
#else
#define debug(...) 42
#endif

const int N = 100010;

int n, k;
int p[N], dp[2][N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> p[i];
  }
  // dp[i][j] = max{dp[i - 1][t - 1] + (p[i] - p[t]}
  for (int id = 1; id <= k; id++) {
    int i = id % 2;
    vector<int> stk(1, -p[1]);
    for (int j = 2; j <= n; j++) {
      dp[i][j] = max(dp[i][j - 1], p[j] + stk[0]);
      int get = dp[i ^ 1][j - 1] - p[j];
      while (!stk.empty() && stk.back() <= get) {
        stk.pop_back();
      }
      stk.push_back(get);
    }
  }
  cout << dp[k & 1][n] << '\n';
  return 0;
}
