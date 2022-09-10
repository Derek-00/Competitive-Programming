/**
 *    author:  willy
 *    created: Thu, 04 Nov 2021 13:14:31 GMT
**/
#include <bits/stdc++.h>

using namespace std;

struct point {
  int x;
  int y;

  point() : x(0), y(0) {
  }

  point(int _x, int _y) : x(_x), y(_y) {
  }

  inline point operator - (const point& rhs) const {
    return point(x - rhs.x, y - rhs.y);
  }
};

int sign(int x) {
  if (x == 0) {
    return 0;
  }
  if (x < 0) {
    return -1;
  }
  return 1;
}

int cross(point a, point b) {
  return a.x * b.y - a.y * b.x;
}

int dot(point a, point b) {
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

double dist(point a, point b) {
  return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

double Dist(point a, point b, point c) { // the distance between point c and seg(a, b)
  point seg = b - a;
  if (sign(dot(b - a, c - a)) <= 0) { // left side
    return (double) dist(a, c);
  }
  if (sign(dot(a - b, c - b)) <= 0) { // right side
    return (double) dist(b, c);
  }
  int prod = abs(cross(b - a, c - a));
  return (double) prod / (double) dist(a, b);
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
    cout << fixed << setprecision(10);
    if (intersection(p[0], p[1], p[2], p[3])) {
      cout << 0 << '\n';
    } else {
      double d1 = Dist(p[2], p[3], p[0]);
      double d2 = Dist(p[2], p[3], p[1]);
      double d3 = Dist(p[0], p[1], p[2]);
      double d4 = Dist(p[0], p[1], p[3]);
      cout << min({d1, d2, d3, d4}) << '\n';
    }
  }
  return 0;
}
