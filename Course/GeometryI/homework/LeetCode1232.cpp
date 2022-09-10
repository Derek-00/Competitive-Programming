/**
 *    author:  willy
 *    created: Thu, 04 Nov 2021 00:50:03 GMT
**/
#include <bits/stdc++.h>

using namespace std;

struct point {
  int x;
  int y;

  point(int x, int y) : x(x), y(y) {
  }

  inline point Vector(point rhs) const {
    return point(rhs.x - x, rhs.y - y);
  }

  inline int cross(point rhs) const {
    return x * rhs.y - y * rhs.x;
  }
};

bool checkStraightLine(vector<vector<int>>& c) {
  point p0 = point(c[0][0], c[0][1]);
  point v0 = p0.Vector(point(c[1][0], c[1][1]));
  for (int i = 2; i < (int) c.size(); i++) {
    point p1 = point(c[i][0], c[i][1]);
    point v1 = p0.Vector(p1);
    if (v0.cross(v1) != 0) {
      return false;
    }
  }
  return true;
}
