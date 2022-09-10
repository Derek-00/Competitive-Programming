/**
 *    author:  willy
 *    created: Sat, 02 Oct 2021 04:41:18 GMT
**/
#include <bits/stdc++.h>

using namespace std;

// problem URL: https://zerojudge.tw/ShowProblem?problemid=e720

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
  int stamp = 0;
  int ans = 0;
  // to count points
  int cnt = 1;
  vector<bool> vis(n, false);
  function<void(int)> do_dfs = [&](int u) {
    for (const auto &v : g[u]) {
      if (!vis[v]) {
        cnt++;
        vis[v] = true;
        do_dfs(v);
      }
    }
  };
  auto init = [&](int u, int v) {
    cnt = 1;
    fill(vis.begin(), vis.end(), false);
    vis[u] = vis[v] = true;
  };
  function<void(int, int)> dfs = [&](int u, int pv) {
    pos[u] = low[u] = ++stamp;
    for (const auto &v : g[u]) {
      if (pos[v] == 0) {
        dfs(v, u);
        low[u] = min(low[u], low[v]);
        if (low[v] > pos[u]) {
          init(u, v);
          do_dfs(v);
          ans = max(ans, cnt * (n - cnt));
        }
      } else {
        if (v != pv) {
          low[u] = min(low[u], pos[v]);
        }
      }
    }
  };
  dfs(0, 0);
  cout << ans << '\n';
  return 0;
}
