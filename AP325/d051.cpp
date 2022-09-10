/**
 *    author:  wy
 *    created: Sat, 09 Jul 2022 16:28:17 GMT
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "C:\Users\wy\C++\solve\_debug\debug.h"
#else
#define debug(...) 42
#endif

int n;
int ans;
int mn = (int) 1e9;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    ans = max(ans, x - mn);
    mn = min(mn, x);
  }
  cout << ans << '\n';
  return 0;
}
