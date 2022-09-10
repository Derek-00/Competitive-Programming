/**
 *    author:  wy
 *    created: Wed, 13 Jul 2022 08:26:08 GMT
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "C:\Users\wy\C++\solve\_debug\debug.h"
#else
#define debug(...) 42
#endif

const int N = 100010;

int n;
int c[N], dp[N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> c[i];
  }
  if (n == 1) {
    cout << c[0] << '\n';
    return 0;
  }
  dp[0] = c[0];
  dp[1] = c[1];
  dp[2] = c[2] + min(dp[0], dp[1]);
  for (int i = 3; i < n; i++) {
    dp[i] = min({dp[i - 3], dp[i - 2], dp[i - 1]}) + c[i];
  }
  cout << min(dp[n - 2], dp[n - 1]) << '\n';
  return 0;
}
