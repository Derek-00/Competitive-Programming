/**
 *    author:  willy
 *    created: Thu, 03 Feb 2022 15:00:02 GMT
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "C:\Users\wy\C++\solve\_debug\debug.h"
#else
#define debug(...) 42
#endif

const int N = 3410;
const int M = 12900;

int n, m;
int w[N], d[N];
int dp[M];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> w[i] >> d[i];
  }
  for (int i = 1; i <= n; i++) {
    for (int j = m; j >= w[i]; j--) {
      dp[j] = max(dp[j], dp[j - w[i]] + d[i]);
    }
  }
  cout << dp[m] << '\n';
  return 0;
}
