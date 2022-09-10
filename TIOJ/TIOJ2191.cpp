/**
 *    author:  willy
 *    created: Sun, 26 Dec 2021 09:06:27 GMT
**/
#include <bits/stdc++.h>

using namespace std;

#define int long long

struct point {
  int x;
  int y;
  int w;

  inline int operator * (const point& rhs) const {
    return (int) ((long long) x * rhs.y - y * rhs.x);
  }

  inline bool operator < (const point& rhs) const {
    return (*this * rhs) < 0;
  }
};

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<point> p(n);
  for (int i = 0; i < n; i++) {
    cin >> p[i].x >> p[i].y >> p[i].w;
    if (p[i].x < 0) {
      p[i].x *= -1;
      p[i].y *= -1;
    } else {
      if (p[i].x == 0 && p[i].y < 0) {
        p[i].y *= -1;
      }
    }
  }
  sort(p.begin(), p.end());
  vector<int> w;
  int j = 0;
  for (int i = 0; i < n; i = j) {
    int val = 0;
    while (j < n && p[i] * p[j] == 0) {
      val += p[j++].w;
    }
    w.push_back(val);
  }
  int mx = 0;
  int cur = 0;
  for (int i = 0; i < (int) w.size(); i++) {
    cur += w[i];
    mx = max(mx, cur);
    cur = max(cur, 0LL);
  }
  cur = 0;
  int mn = 0;
  for (int i = 0; i < (int) w.size(); i++) {
    cur += w[i];
    mn = min(mn, cur);
    cur = min(cur, 0LL);
  }
  cout << max(mx, accumulate(w.begin(), w.end(), 0LL) - mn) << '\n';
  return 0;
}
