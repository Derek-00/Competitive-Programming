/**
 *    author:  willy
 *    created: Sat, 02 Oct 2021 14:19:29 GMT
**/
#include <bits/stdc++.h>

using namespace std;

// problem URL: https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=551

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  int Case = 0;
  while (cin >> n >> m) {
    if (n == 0 && m == 0) {
      break;
    }
    vector<vector<int>> g(n);
    for (int i = 0; i < m; i++) {
      int u, v;
      cin >> u >> v;
      --u; --v;
      g[u].push_back(v);
      g[v].push_back(u);
    }
    vector<int> pos(n);
    vector<int> low(n);
    vector<vector<bool>> is_bridge(n, vector<bool>(n, false));
    int stamp = 0;
    set<pair<int, int>> ans;
    function<void(int, int)> dfs = [&](int u, int pr) {
      pos[u] = low[u] = ++stamp;
      for (const auto &v : g[u]) {
        if (pos[v] == 0) { // tree edge
          dfs(v, u);
          ans.emplace(u, v);
          low[u] = min(low[u], low[v]);
          if (low[v] > pos[u]) {
            ans.emplace(v, u);
          }
        } else {
          if (v != pr) { // back edge
            if (pos[v] < pos[u]) {
              ans.emplace(u, v);
            }
            low[u] = min(low[u], pos[v]);
          }
        }
      }
    };
    dfs(0, 0);
    cout << ++Case << '\n';
    for (const auto &e : ans) {
      int i = e.first + 1;
      int j = e.second + 1;
      cout << '\n' << i << " " << j;
    }
    cout << '\n' << '#' << '\n';
  }
  return 0;
}
