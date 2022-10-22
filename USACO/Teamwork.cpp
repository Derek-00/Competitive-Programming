/**
 *    author:  wy
 *    created: Sat, 22 Oct 2022 16:01:14 GMT
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "C:\Users\wy\C++\solve\_debug\debug.h"
#else
#define debug(...) 42
#endif

const int N = 1010;

int a[N], dp[N];

void setIO() {
  freopen("teamwork.in", "r", stdin);
  freopen("teamwork.out", "w", stdout);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  setIO();
  int n, k;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    int mx = 0;
    for (int j = i; j > max(0, i - k); j--) {
      mx = max(mx, a[j]);
      int lvl = (i - j + 1) * mx;
      dp[i] = max(dp[i], dp[j - 1] + lvl);
    }
  }
  cout << dp[n] << '\n';
  return 0;
}
