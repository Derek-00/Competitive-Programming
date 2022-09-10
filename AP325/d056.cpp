/**
 *    author:  wy
 *    created: Tue, 12 Jul 2022 06:42:45 GMT
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

struct Point {
  int x;
  int y;
} a[N], b[N];

inline bool Cmpx(const Point& pa, const Point& pb) {
  if (pa.x == pb.x) {
    return pa.y < pb.y;
  }
  return pa.x < pb.x;
}

inline bool Cmpy(const Point& pa, const Point& pb) {
  return pa.y < pb.y;
}

inline int Dist(const Point& pa, const Point& pb) {
  return abs(pa.x - pb.x) + abs(pa.y - pb.y);
}

int Solve(int l, int r) {
  if (r - l <= 2) {
    int ans = (int) 1e9;
    for (int i = l; i < r; i++) {
      for (int j = i + 1; j < r; j++) {
        ans = min(ans, Dist(a[i], a[j]));
      }
    }
    sort(a + l, a + r, Cmpy);
    return ans;
  }
  int mid = (l + r) >> 1;
  int midx = a[mid].x;
  int dist = min(Solve(l, mid), Solve(mid, r));
  merge(a + l, a + mid, a + mid, a + r, b, Cmpy);
  copy(b, b + r - l, a + l);
  int k = 0;
  for (int i = l; i < r; i++) {
    if (abs(a[i].x - midx) >= dist) {
      continue;
    }
    for (int j = k - 1; j >= 0; j--) {
      if (a[i].y - b[j].y >= dist) {
        break;
      }
      dist = min(dist, Dist(a[i], b[j]));
    }
    b[k++] = a[i];
  }
  return dist;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i].x >> a[i].y;
  }
  sort(a, a + n, Cmpx);
  cout << Solve(0, n) << '\n';
  return 0;
}
