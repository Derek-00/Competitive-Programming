/**
 *    author:  willy
 *    created: Thu, 04 Nov 2021 15:25:10 GMT
**/
#include <bits/stdc++.h>

using namespace std;

struct point {
  long long x;
  long long y;

  point() : x(0), y(0) {
  }

  point(long long _x, long long _y) : x(_x), y(_y) {
  }

  inline point operator - (const point& rhs) const {
    return point(x - rhs.x, y - rhs.y);
  }

  inline point operator + (const point& rhs) const {
    return point(x + rhs.x, y + rhs.y);
  }
};

inline int sign(long long x) {
  return (x == 0 ? 0 : (x < 0 ? -1 : 1));
}

inline long long cross(point a, point b) {
  return (long long) a.x * b.y - a.y * b.x;
}

inline long long dot(point a, point b) {
  return (long long) a.x * b.x + a.y * b.y;
}

bool onseg(point a, point b, point c) {
  if (cross(b - a, c - a) != 0) return false;
  if (sign(dot(b - a, c - a)) < 0) return false;
  if (sign(dot(a - b, c - b)) < 0) return false;
  return true;
}

bool intersection(point a, point b, point c, point d) {
  int c1 = sign(cross(b - a, c - a)) * sign(cross(b - a, d - a));
  int c2 = sign(cross(d - c, a - c)) * sign(cross(d - c, b - c));
  if (c1 > 0 || c2 > 0) {
    return false;
  }
  if (c1 < 0 && c2 < 0) {
    return true;
  }
  if (onseg(a, b, c)) return true;
  if (onseg(a, b, d)) return true;
  if (onseg(c, d, a)) return true;
  if (onseg(c, d, b)) return true;
  return false;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<point> p(n);
  for (int i = 0; i < n; i++) {
    cin >> p[i].x >> p[i].y;
  }
  const point Vector = point(1, (long long) 2e9 + 1);
  while (m--) {
    point np;
    cin >> np.x >> np.y;
    bool found = false;
    for (int i = 0; i < n; i++) {
      if (onseg(p[i], p[(i + 1) % n], np)) {
        cout << "BOUNDARY" << '\n';
        found = true;
        break;
      }
    }
    if (found) continue;
    point nv = np + Vector;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      if (intersection(p[i], p[(i + 1) % n], np, nv)) {
        cnt++;
      }
    }
    cout << (cnt & 1 ? "INSIDE" : "OUTSIDE") << '\n';
  }
  return 0;
}
