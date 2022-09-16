/**
 *    author:  wy
 *    created: Fri, 16 Sep 2022 15:12:29 GMT
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
  vector<vector<int>> a(6);
  array<int, 6> dy = {};
  for (int i = 0; i < 6; i++) {
    int k;
    cin >> k;
    a[i].resize(k);
    for (int j = 0; j < k; j++) {
      cin >> a[i][j];
      --a[i][j];
    }
    int cnt = 0;
    for (int j = 0; j < 6; j++) {
      bool valid = true;
      for (int l = 0; l < k; l++) {
        valid &= (a[i][l] != j);
      }
      if (valid) {
        dy[j] += 1;
      }
    }
  }
  int ans = 1;
  for (int i = 0; i < 6; i++) {
    ans *= dy[i];
  }
  cout << ans << '\n';
  return 0;
}
