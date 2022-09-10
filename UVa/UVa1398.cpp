/**
 *    author:  wy
 *    created: Sun, 03 Jul 2022 13:58:40 GMT
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "C:\Users\wy\C++\solve\_debug\debug.h"
#else
#define debug(...) 42
#endif

struct event {
  double times;
  int type;

  inline bool operator < (const event& rhs) const {
    if (times == rhs.times) {
      return type < rhs.type;
    }
    return times < rhs.times;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int w, h;
    cin >> w >> h;
    int n;
    cin >> n;
    vector<event> e;
    for (int i = 0; i < n; i++) {
      int x, y, a, b;
      cin >> x >> y >> a >> b;
      double mn_t = 0.0;
      double mx_t = (double) 1e9;
      auto Update = [&](int p, int d, int v) {
        if (v == 0) {
          if (p <= 0 || p >= d) {
            mx_t = -1;
          }
        } else {
          if (v > 0) {
            mn_t = max(mn_t, (double) -1.0 * p / v);
            mx_t = min(mx_t, (double) 1.0 * (d - p) / v);
          } else {
            mn_t = max(mn_t, (double) 1.0 * (d - p) / v);
            mx_t = min(mx_t, (double) -1.0 * p / v);
          }
        }
      };
      Update(x, w, a);
      Update(y, h, b);
      if (mn_t < mx_t) {
        e.push_back({mn_t, 1});
        e.push_back({mx_t, -1});
      }
    }
    sort(e.begin(), e.end());
    int cnt = 0;
    int ans = 0;
    for (int i = 0; i < (int) e.size(); i++) {
      cnt += e[i].type;
      ans = max(ans, cnt);
    }
    cout << ans << '\n';
  }
  return 0;
}
