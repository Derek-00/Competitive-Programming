/**
 *    author:  wy
 *    created: Wed, 13 Jul 2022 08:19:47 GMT
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "C:\Users\wy\C++\solve\_debug\debug.h"
#else
#define debug(...) 42
#endif

int n;
int dp[2];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  int j = 0;
  for (int i = 0; i < n; i++) {
    int pay;
    cin >> pay;
    dp[j] = max(dp[j] + pay, dp[j ^ 1]);
    j ^= 1;
  }
  cout << dp[j ^ 1] << '\n';
  return 0;
}
