/**
 *    author:  wy
 *    created: Wed, 13 Jul 2022 08:49:48 GMT
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "C:\Users\wy\C++\solve\_debug\debug.h"
#else
#define debug(...) 42
#endif

int n, m;
int a[210][210];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
      a[i][j] += a[i - 1][j];
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= i; j++) {
      int sum = 0;
      for (int k = 1; k <= m; k++) {
        sum = max(sum + (a[i][k] - a[j - 1][k]), 0);
        ans = max(ans, sum);
      }
    }
  }
  cout << ans << '\n';
  return 0;
}
