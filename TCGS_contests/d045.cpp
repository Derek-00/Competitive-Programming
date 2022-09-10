/**
 *    author:  willy
 *    created: Sat, 06 Nov 2021 07:00:20 GMT
**/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct point {
  int x;
  int y;

  point() : x(0), y(0) {
  }

  inline bool operator < (const point& rhs) const {
    if (x != rhs.x) {
      return x < rhs.x;
    }
    return y > rhs.y;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<point> p(n);
    for (int i = 0; i < n; i++) {
      cin >> p[i].x >> p[i].y;
    }
    sort(p.begin(), p.end());
    vector<point> save(1, p[0]);
    for (int i = 1; i < n; i++) {
      bool found = false;
      for (int j = 0; j < (int) save.size(); j++) {
        if ((save[j].x <= p[i].x && p[i].y <= save[j].y) || save[j].y < p[i].x) {
          save[j] = p[i];
          found = true;
          break;
        }
      }
      if (!found) {
        save.push_back(p[i]);
      }
    }
    cout << (int) save.size() << '\n';
  }
  return 0;
}
