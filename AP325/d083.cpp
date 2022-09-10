/**
 *    author:  wy
 *    created: Sun, 17 Jul 2022 04:03:24 GMT
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "C:\Users\wy\C++\solve\_debug\debug.h"
#else
#define debug(...) 42
#endif

struct Item {
  int p;
  int x, y;

  inline bool operator < (const Item& rhs) const {
    if (x == rhs.x) {
      return y < rhs.y;
    }
    return x > rhs.x;
  }
} a[100010];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i].p);
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i].x);
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i].y);
  }
  sort(a, a + n);
  int ans = 0;
  map<int, int> dp;
  dp.emplace(-1, 0);
  for (int i = 0; i < n; i++) {
    auto it = dp.upper_bound(a[i].y);
    it = prev(it);
    int w = it->second + a[i].p;
    ans = max(ans, w);
    it = dp.insert(it, make_pair(a[i].y, w));
    it->second = max(it->second, w);
    it = next(it);
    while (it != dp.end() && it->second <= w) {
      it = dp.erase(it);
    }
  }
  printf("%d\n", ans);
  return 0;
}
