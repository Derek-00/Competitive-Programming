/**
 *    author:  wy
 *    created: Thu, 14 Jul 2022 05:54:30 GMT
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "C:\Users\wy\C++\solve\_debug\debug.h"
#else
#define debug(...) 42
#endif

const int N = 110;
const int M = 200010;

int n, m, s;
int f[N], dp[M];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m >> s;
  for (int i = 1; i <= n; i++) {
    cin >> f[i];
  }
  int sum = accumulate(f + 1, f + n + 1, 0);
  int need = s - (m - sum);
  if (need <= 0) {
    cout << 0 << '\n';
    return 0;
  }
  dp[0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = M - 1; j >= f[i]; j--) {
      if (dp[j - f[i]]) {
        dp[j] = 1;
      }
    }
  }
  for (int i = need; i < M; i++) {
    if (dp[i]) {
      cout << i << '\n';
      return 0;
    }
  }
  return 0;
}
