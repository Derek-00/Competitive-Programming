/**
 *    author:  wy
 *    created: Thu, 14 Jul 2022 14:06:32 GMT
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "C:\Users\wy\C++\solve\_debug\debug.h"
#else
#define debug(...) 42
#endif

const int N = 100010;

int n, k;
int a[N], dp[N];
vector<int> stk;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i <= k; i++) {
    dp[i] = a[i];
  }
  stk.push_back(a[0]);
  for (int i = k + 1; i < n; i++) {
    int ls = i - k - 1;
    while (!stk.empty() && stk.back() <= dp[ls]) {
      stk.pop_back();
    }
    stk.push_back(dp[ls]);
    assert(!stk.empty());
    dp[i] = stk[0] + a[i];
  }
  cout << *max_element(dp, dp + n) << '\n';
  return 0;
}
