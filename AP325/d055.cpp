/**
 *    author:  wy
 *    created: Sat, 09 Jul 2022 16:36:06 GMT
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "C:\Users\wy\C++\solve\_debug\debug.h"
#else
#define debug(...) 42
#endif

int n;
vector<int> stk;

struct Point {
  int x;
  int y;

  inline bool operator < (const Point& rhs) const {
    if (x == rhs.x) {
      return y < rhs.y;
    }
    return x > rhs.x;
  }
} p[100010];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> p[i].x;
  }
  for (int i = 0; i < n; i++) {
    cin >> p[i].y;
  }
  sort(p, p + n);
  int mx_y = -1;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (mx_y < p[i].y) {
      ans += 1;
      mx_y = p[i].y;
    }
  }
  cout << ans << '\n';
  return 0;
}
