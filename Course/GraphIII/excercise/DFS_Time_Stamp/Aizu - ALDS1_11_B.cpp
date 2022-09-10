/**
 *    author:  willy
 *    created: Tue, 28 Sep 2021 14:20:48 GMT
**/
#include <bits/stdc++.h>

using namespace std;

// problem URL: https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_11_B

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<vector<int>> g(n);
  for (int i = 0; i < n; i++) {
    int u, k;
    cin >> u >> k;
    --u;
    g[u].resize(k);
    for (int j = 0; j < k; j++) {
      cin >> g[u][j];
      --g[u][j];
    }
  }
  vector<pair<int, int>> t(n, make_pair(0, 0));
  int step = 1;
  function<void(int)> dfs = [&](int id) {
    t[id].first = step++;
    for (const auto &v : g[id]) {
      if (t[v].first == 0) {
        dfs(v);
      }
    }
    t[id].second = step++;
  };
  for (int i = 0; i < n; i++) {
    if (t[i].first == 0) {
      dfs(i);
    }
  }
  for (int i = 0; i < n; i++) {
    cout << i + 1 << " " << t[i].first << " " << t[i].second << '\n';
  }
  return 0;
}
