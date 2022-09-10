/**
 *    author:  wy
 *    created: Mon, 04 Jul 2022 16:26:26 GMT
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
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int> b(m);
  for (int i = 0; i < m; i++) {
    cin >> b[i];
  }
  sort(b.begin(), b.end());
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (binary_search(b.begin(), b.end(), k - a[i])) {
      ans += 1;
    }
  }
  cout << ans << '\n';
  return 0;
}
