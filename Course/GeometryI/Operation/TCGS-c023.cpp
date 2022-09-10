/**
 *    author:  willy
 *    created: Thu, 04 Nov 2021 00:36:58 GMT
**/
#include <iostream>
#include <vector>

using namespace std;

struct point {
  int x;
  int y;

  point() {
    x = y = 0.0;
  }

  inline int Dist() const {
    return x * x + y * y;
  }
};

int main() {
  #ifdef LOCAL
  ios::sync_with_stdio(false);
  cin.tie(0);
  #endif
  int n;
  cin >> n;
  vector<point> p(n);
  for (int i = 0; i < n; i++) {
    cin >> p[i].x >> p[i].y;
  }
  int id = 0;
  int mx = p[0].Dist();
  for (int i = 1; i < n; i++) {
    if (mx < p[i].Dist()) {
      id = i;
      mx = p[i].Dist();
    }
  }
  cout << id + 1 << " " << mx << '\n';
  return 0;
}
