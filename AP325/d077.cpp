/**
 *    author:  wy
 *    created: Thu, 14 Jul 2022 14:27:10 GMT
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "C:\Users\wy\C++\solve\_debug\debug.h"
#else
#define debug(...) 42
#endif

const int N = 200010;

int n, k;
int c[N], dp[N], deq[N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> c[i];
  }
  int l = 0, r = 0;
  deq[r++] = 1;
  dp[1] = c[1];
  for (int i = 2; i <= n; i++) {
    if (i <= k + 1) {
      dp[i] = c[i];
    } else {
      while (deq[l] < i - 2 * k - 1) {
        l += 1;
      }
      dp[i] = dp[deq[l]] + c[i];
    }
    while (l < r && dp[deq[r - 1]] > dp[i]) {
      r -= 1;
    }
    deq[r++] = i;
  }
  cout << *min_element(dp + (n - k), dp + (n + 1)) << '\n';
  return 0;
}
