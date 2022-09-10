/**
 *    author:  wy
 *    created: Mon, 11 Jul 2022 07:31:02 GMT
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "C:\Users\wy\C++\solve\_debug\debug.h"
#else
#define debug(...) 42
#endif

int n;
int x, y;

struct Point {
  int s, t;

  inline bool operator < (const Point& rhs) const {
    if (s == rhs.s) {
      return t < rhs.t;
    }
    return s < rhs.s;
  }
} p[100010];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  cin >> x >> y;
  for (int i = 0; i < n; i++) {
    cin >> p[i].s >> p[i].t;
  }
  sort(p, p + n);
  int beg = 0;
  int end = -1;
  for (int i = 0; i < n; i++) {
    if (p[i].s <= x && end <= p[i].t) {
      end = p[i].t;
      beg = i;
    }
  }
  if (end == -1){
    cout << -1 << '\n';
    return 0;
  }
  int cnt = 1;
  for (int i = beg + 1; i < n; i++) {
    if (end >= y) {
      break;
    }
    if (p[i].s > end) {
      cout << -1 << '\n';
      return 0;
    }
    if (p[i].t <= end) {
      continue;
    }
    cnt += 1;
    int mx = p[i].t;
    while (i + 1 < n && p[i + 1].s <= end) {
      mx = max(mx, p[++i].t);
    }
    end = mx;
  }
  cout << (end < y ? -1 : cnt) << '\n';
  return 0;
}
