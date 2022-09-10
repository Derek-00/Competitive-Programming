/**
 *    author:  willy
 *    created: Sun, 10 Oct 2021 10:21:10 GMT
**/
#include <bits/stdc++.h>

using namespace std;

// problem URL: https://codeforces.com/contest/1572/problem/A

vector<int> find_topsort(const vector<vector<int>> &g) {
  int n = (int) g.size();
  vector<int> deg(n, 0);
  for (int i = 0; i < n; i++) {
    for (auto &v : g[i]) {
      deg[v]++;
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
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    for (int i = 0; i < n; i++) {
      int k;
      cin >> k;
      for (int j = 0; j < k; j++) {
        int a;
        cin >> a;
        --a;
        g[a].push_back(i);
      }
    }
    auto tp = find_topsort(g);
    if (tp.empty()) {
      cout << -1 << '\n';
      continue;
    }
    vector<int> dp(n);
    for (int id = 0; id < n; id++) {
      int i = tp[id];
      for (auto &to : g[i]) {
        dp[to] = max(dp[to], dp[i] + (i > to));
      }
    }
    cout << *max_element(dp.begin(), dp.end()) + 1 << '\n';
  }
  return 0;
}
