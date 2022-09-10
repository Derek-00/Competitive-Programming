/**
 *    author:  willy
 *    created: Sat, 02 Oct 2021 10:57:15 GMT
**/
#include <bits/stdc++.h>

using namespace std;

// problem URL:https://open.kattis.com/problems/caveexploration

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  vector<int> pos(n);
  vector<int> low(n);
  vector<vector<bool>> is_bridge(n, vector<bool>(n, false));
  int stamp = 0;
  function<void(int, int)> dfs = [&](int u, int pr) {
    pos[u] = low[u] = ++stamp;
    for (const auto &v : g[u]) {
      if (pos[v] == 0) {
        dfs(v, u);
        low[u] = min(low[u], low[v]);
        if (low[v] > pos[u]) {
          is_bridge[u][v] = is_bridge[v][u] = true;
        }
      } else {
        if (v != pr) { // back edge
          low[u] = min(low[u], pos[v]);
        }
      }
    }
  };
  dfs(0, 0);
  int ans = 0;
  vector<bool> vis(n, false);
  function<void(int)> do_dfs_from = [&](int u) {
    ans += 1;
    vis[u] = true;
    for (const auto &v : g[u]) {
      if (vis[v] || is_bridge[u][v]) {
        continue;
      }
      do_dfs_from(v);
    }
  };
  do_dfs_from(0);
  cout << ans << '\n';
  return 0;
}
