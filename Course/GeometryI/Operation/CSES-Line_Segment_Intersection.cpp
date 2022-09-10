/**
 *    author:  willy
 *    created: Thu, 04 Nov 2021 12:34:34 GMT
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
};

int sign(long long x) {
  if (x == 0) {
    return 0;
  }
  if (x < 0) {
    return -1;
  }
  return 1;
}

long long cross(point a, point b) {
  return (long long) a.x * b.y - a.y * b.x;
}

long long dot(point a, point b) {
  return a.x * b.x + a.y * b.y;
}

bool onseg(point a, point b, point c) { // if c is on seg(a, b)
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
  int tt;
  cin >> tt;
  while (tt--) {
    vector<point> p(4);
    for (int i = 0; i < 4; i++) {
      cin >> p[i].x >> p[i].y;
    }
    cout << (intersection(p[0], p[1], p[2], p[3]) ? "YES" : "NO") << '\n';
  }
  return 0;
}
