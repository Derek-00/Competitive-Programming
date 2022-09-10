/**
 *    author:  wy
 *    created: Sat, 09 Jul 2022 16:30:18 GMT
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "C:\Users\wy\C++\solve\_debug\debug.h"
#else
#define debug(...) 42
#endif

int n;
long long sum, ans;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    sum = max(0LL, (long long) sum + x);
    ans = max(ans, sum);
  }
  cout << ans << '\n';
  return 0;
}
