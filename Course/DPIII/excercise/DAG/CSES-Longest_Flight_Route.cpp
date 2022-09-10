/**
 *    author:  willy
 *    created: Thu, 07 Oct 2021 14:29:15 GMT
**/
#include <bits/stdc++.h>

using namespace std;

// problem URL: https://cses.fi/problemset/task/1680/

vector<int> find_topsort(const vector<vector<int>> &g) {
  int n = (int) g.size();
  vector<int> deg(n, 0);
  for (int v = 0; v < n; v++) {
    for (auto &to : g[v]) {
      deg[to]++;
    }
  }
  vector<int> x;
  for (int i = 0; i < n; i++) {
    if (deg[i] == 0) {
      x.push_back(i);
    }
  }
  for (int ptr = 0; ptr < (int) x.size(); ptr++) {
    int i = x[ptr];
    for (auto &to : g[i]) {
      if (--deg[to] == 0) {
        x.push_back(to);
      }
    }
  }
  if ((int) x.size() != n) {
    return vector<int>();
  }
  return x;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    --a; --b;
    g[a].push_back(b);
  }
  auto tp = find_topsort(g);
  if (tp.empty()) {
    cout << "IMPOSSIBLE" << '\n';
    return 0;
  }
  const int inf = (int) 1e9;
  vector<int> dp(n, -inf);
  vector<int> from(n, -1);
  dp[0] = 1;
  for (int i = 0; i < n; i++) {
    int v = tp[i];
    for (auto &to : g[v]) {
      if (dp[to] < dp[v] + 1) {
        dp[to] = dp[v] + 1;
        from[to] = v;
      }
    }
  }
  if (dp.back() < 0) {
    cout << "IMPOSSIBLE" << '\n';
    return 0;
  }
  function<void(int)> print = [&](int v) {
    if (v == -1) {
      return;
    }
    print(from[v]);
    cout << v + 1;
    if (v + 1 != n) {
      cout << " ";
    }
  };
  cout << dp.back() << '\n';
  print(n - 1);
  return 0;
}
