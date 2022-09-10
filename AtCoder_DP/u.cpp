/**
 *    author:  willy
 *    created: Fri, 10 Dec 2021 07:11:58 GMT
**/
#include <bits/stdc++.h>

using namespace std;

long long a[16][16];
long long dp[1 << 16];
long long all[1 << 16];

long long Solve(int s) {
  if (dp[s] != -1) {
    return dp[s];
  }
  long long res = all[s];
  for (int i = (s - 1) & s; i > 0; i = (i - 1) & s) {
    res = max(res, Solve(s ^ i) + all[i]);
  }
  return dp[s] = res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
    }
  }
  for (int s = 0; s < (1 << 16); s++) {
    for (int i = 0; i < n; i++) {
      if (!(s & (1 << i))) continue;
      for (int j = i + 1; j < n; j++) {
        if (!(s & (1 << j))) continue;
        all[s] += a[i][j];
      }
    }
  }
  memset(dp, -1, sizeof(dp));
  dp[0] = 0;
  cout << Solve((1 << n) - 1) << '\n';
  return 0;
}
