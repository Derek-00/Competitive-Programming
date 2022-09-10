/**
 *    author:  willy
 *    created: Fri, 05 Nov 2021 11:22:34 GMT
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

long long cross(point a, point b) {
  return (long long) a.x * b.y - a.y * b.x;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<point> p(n);
  for (int i = 0; i < n; i++) {
    cin >> p[i].x >> p[i].y;
  }
  long long boundary = 0;
  long long area = 0;
  for (int i = 0; i < n; i++) {
    point d = p[(i + 1) % n] - p[i];
    boundary += __gcd(abs(d.x), abs(d.y));
    area += cross(p[i], p[(i + 1) % n]);
  }
  area = abs(area);
  long long inside = (area - boundary + 2) >> 1;
  cout << inside << " " << boundary << '\n';
  return 0;
}
