/**
 *    author:  willy
 *    created: Thu, 09 Sep 2021 15:19:21 GMT
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  while (cin >> n && n) {
    vector<pair<double, double>> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i].first >> a[i].second;
    }
    sort(a.begin(), a.end());
    const double MAX = (double) 1e4;
    function<double(int, int)> DNC = [&](int l, int r) {
      if (l >= r) {
        return MAX;
      }
      double m = (l + r) >> 1;
      double d = min(DNC(l, m), DNC(m + 1, r));
      vector<pair<double, double>> tmp;
      for (int i = m; i >= l && a[m].first - a[i].first < d; i--) {
        tmp.push_back(a[i]);
      }
      for (int i = m + 1; i <= r && a[i].first - a[m].first < d; i++) {
        tmp.push_back(a[i]);
      }
      sort(tmp.begin(), tmp.end(), [&](pair<double, double> a, pair<double, double> b) {
        return make_pair(a.second, a.first) < make_pair(b.second, b.first);
      });
      auto dist = [&](pair<double, double> a, pair<double, double> b) {
        return sqrt((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));
      };
      int sz = (int) tmp.size();
      for (int i = 0; i < sz; i++) {
        for (int j = 1; j < 4 && i + j < sz; j++) {
          d = min(d, dist(tmp[i], tmp[i + j]));
        }
      }
      return d;
    };
    double ret = DNC(0, n - 1);
    if (ret >= MAX) {
      cout << "INFINITY" << '\n';
    } else {
      cout << fixed << setprecision(4) << ret << '\n';
    }
  }
  return 0;
}
