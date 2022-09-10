/**
 *    author:  wy
 *    created: Fri, 08 Jul 2022 12:21:26 GMT
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "C:\Users\wy\C++\solve\_debug\debug.h"
#else
#define debug(...) 42
#endif

const int N = 100010;

int n;
long long ans;

struct Item {
  int t, w;

  inline bool operator < (const Item& rhs) const {
    return t * rhs.w < rhs.t * w;
  }
} a[N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i].t;
  }
  for (int i = 0; i < n; i++) {
    cin >> a[i].w;
  }
  sort(a, a + n);
  int t = 0;
  for (int i = 0; i < n; i++) {
    t += a[i].t;
    ans += 1LL * a[i].w * t;
  }
  cout << ans << '\n';
  return 0;
}
