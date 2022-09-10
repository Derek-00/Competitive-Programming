/**
 *    author:  willy
 *    created: Tue, 14 Dec 2021 13:11:19 GMT
**/
#include <bits/stdc++.h>

using namespace std;

struct line {
  long long a;
  long long b;

  inline long long calc(const long long& x) const {
    return a * x + b;
  }

  inline bool Better(const line& l1, const line& l2) const {
    return (b - l1.b) * (l2.a - a) >= (b - l2.b) * (l1.a - a);
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  long long c;
  cin >> n >> c;
  vector<long long> h(n);
  for (int i = 0; i < n; i++) {
    cin >> h[i];
  }
  // dp[i] = c + h[i]^2 + min((-2h[j]) * h[i] + (dp[j] + h[j]^2)
  vector<long long> dp(n);
  deque<line> hull;
  auto Add = [&](int id) {
    long long a = -2 * h[id];
    long long b = dp[id] + h[id] * h[id];
    line nl = {a, b};
    while ((int) hull.size() >= 2 && nl.Better(hull[hull.size() - 2], hull.back())) {
      hull.pop_back();
    }
    hull.push_back(nl);
  };
  dp[0] = 0;
  Add(0);
  for (int i = 1; i < n; i++) {
    while ((int) hull.size() >= 2 && hull[0].calc(h[i]) >= hull[1].calc(h[i])) {
      hull.pop_front();
    }
    dp[i] = c + h[i] * h[i] + hull[0].calc(h[i]);
    Add(i);
  }
  cout << dp[n - 1] << '\n';
  return 0;
}
