/**
 *    author:  wy
 *    created: Wed, 06 Jul 2022 07:42:40 GMT
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
  int n, k;
  cin >> n >> k;
  int sum = 0;
  set<int> s = {0};
  int ans = (int) -1e9;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    sum += x;
    auto it = s.lower_bound(sum - k);
    if (it != s.end()) {
      ans = max(ans, sum - *it);
    }
    s.insert(sum);
  }
  cout << ans << '\n';
  return 0;
}
