/**
 *    author:  willy
 *    created: Sun, 03 Oct 2021 11:51:15 GMT
**/
#include <bits/stdc++.h>

using namespace std;

// problem URL: https://cses.fi/problemset/task/1683/

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n);
  vector<vector<int>> g_rev(n);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    --a; --b;
    g[a].push_back(b);
    g_rev[b].push_back(a);
  }
  vector<int> order;
  vector<bool> was(n, false);
  function<void(int)> dfs1 = [&](int u) {
    was[u] = true;
    for (const auto &v : g[u]) {
      if (!was[v]) {
        dfs1(v);
      }
    }
    order.push_back(u);
  };
  for (int i = 0; i < n; i++) {
    if (!was[i]) {
      dfs1(i);
    }
  }
  vector<int> c(n, -1);
  function<void(int)> dfs2 = [&](int u) {
    for (const auto &v : g_rev[u]) {
      if (c[v] == -1) {
        c[v] = c[u];
        dfs2(v);
      }
    }
  };
  int cnt = 0;
  for (int id = n - 1; id >= 0; id--) {
    int i = order[id];
    if (c[i] != -1) {
      continue;
    }
    c[i] = cnt++;
    dfs2(i);
  }
  cout << cnt << '\n';
  for (int i = 0; i < n; i++) {
    cout << c[i] + 1 << " \n"[i == n - 1];
  }
  return 0;
}
