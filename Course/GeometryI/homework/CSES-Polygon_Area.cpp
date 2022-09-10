/**
 *    author:  willy
 *    created: Thu, 04 Nov 2021 01:08:45 GMT
**/
#include <bits/stdc++.h>

using namespace std;

struct point {
  long long x;
  long long y;

  point() : x(0), y(0) {
  }

  point(long long x, long long y) : x(x), y(y) {
  }

  inline long long cross(point rhs) const {
    return x * rhs.y - y * rhs.x;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<point> p(n);
  for (int i = 0; i < n; i++) {
    cin >> p[i].x >> p[i].y;
  }
  long long area = 0;
  for (int i = 0; i < n; i++) {
    area += p[i].cross(p[(i + 1) % n]);
  }
  cout << abs(area) << '\n';
  return 0;
}
