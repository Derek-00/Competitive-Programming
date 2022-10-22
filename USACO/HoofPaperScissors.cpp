/**
 *    author:  wy
 *    created: Sat, 22 Oct 2022 08:43:26 GMT
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "C:\Users\wy\C++\solve\_debug\debug.h"
#else
#define debug(...) 42
#endif

const int N = 100010;

int a[N], dp[N][30][5];

void setIO() {
  freopen("hps.in", "r", stdin);
  freopen("hps.out", "w", stdout);
}

inline int encode(char x) {
  if (x == 'H') return 0;
  if (x == 'P') return 1;
  if (x == 'S') return 2;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  setIO();
  int n, c;
  cin >> n >> c;
  for (int i = 1; i <= n; i++) {
    char x;
    cin >> x;
    a[i] = encode(x);
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= c; j++) {
      for (int k = 0; k < 3; k++) {
        for (int l = 0; l < 3; l++) { // k to l
          int diff = (k != l ? 1 : 0);
          int win = (l == a[i] ? 1 : 0);
          dp[i][j + diff][l] = max(dp[i][j + diff][l], dp[i - 1][j][k] + win);
        }
      }
    }
  }
  int ans = 0;
  for (int k = 0; k < 3; k++) {
    ans = max(ans, dp[n][c][k]);
  }
  cout << ans << '\n';
  return 0;
}
