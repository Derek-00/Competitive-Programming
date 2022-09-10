/**
 *    author:  willy
 *    created: Wed, 15 Dec 2021 14:34:36 GMT
**/
#include <bits/stdc++.h>

using namespace std;

struct line {
  long long x;
  long long y;
  long long a;

  inline bool operator < (const line& rhs) const {
    return x < rhs.x;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<line> p(n);
  for (int i = 0; i < n; i++) {
    cin >> p[i].x >> p[i].y >> p[i].a;
  }
  sort(p.begin(), p.end());
  /*
  dp[i] = max(dp[j]) + x[i] * y[i] - x[j] * y[i] - a[i]
  dp[i] = x[i] * y[i] - a[i] + max(-x[j] * y[i] + dp[j])
  dp[i] = max((x[i] - x[j]) * y[i] + dp[j]) - a[i] */
  vector<long long> dp(n);
  for (int i = 0; i < n; i++) {
    dp[i] = p[i].x * p[i].y - p[i].a;
  }
  deque<int> hull;
  auto intersect = [&](int x, int y) -> double {
    return (double) ((dp[y] - dp[x]) / (p[y].x - p[x].x));
  };
  auto Add = [&](int i) {
    while ((int) hull.size() >= 2 && intersect(hull[hull.size() - 2], hull.back()) <= intersect(hull.back(), i)) {
      hull.pop_back();
    }
    hull.push_back(i);
  };
  Add(0);
  for (int i = 1; i < n; i++) {
    while ((int) hull.size() >= 2 && (p[i].x - p[hull[0]].x) * p[i].y + dp[hull[0]] <= (p[i].x - p[hull[1]].x) * p[i].y + dp[hull[1]]) {
      hull.pop_front();
    }
    dp[i] = max(dp[i], (p[i].x - p[hull[0]].x) * p[i].y + dp[hull[0]] - p[i].a);
    Add(i);
  }
  cout << *max_element(dp.begin(), dp.end()) << '\n';
  return 0;
}
