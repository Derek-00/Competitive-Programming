/**
 *    author:  wy
 *    created: Fri, 08 Jul 2022 14:21:34 GMT
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "C:\Users\wy\C++\solve\_debug\debug.h"
#else
#define debug(...) 42
#endif

const int N = (int) 1e5;

struct Item {
  int w, f;

  inline bool operator < (const Item& rhs) const {
    return w * rhs.f < rhs.w * f;
  }
} a[N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i].w;
  }
  for (int i = 0; i < n; i++) {
    cin >> a[i].f;
  }
  sort(a, a + n);
  int wsum = 0;
  long long ans = 0;
  for (int i = 1; i < n; i++) {
    wsum += a[i - 1].w;
    ans += 1LL * wsum * a[i].f;
  }
  cout << ans << '\n';
  return 0;
}
