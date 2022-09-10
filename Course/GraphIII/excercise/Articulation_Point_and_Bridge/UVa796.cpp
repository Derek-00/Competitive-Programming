/**
 *    author:  willy
 *    created: Fri, 01 Oct 2021 14:08:00 GMT
**/
#include <bits/stdc++.h>

using namespace std;

// problem URL: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=9&page=show_problem&problem=737

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  while (cin >> n) {
    vector<vector<int>> g(n);
    for (int i = 0; i < n; i++) {
      int u;
      cin >> u;
      string s;
      cin >> s;
      int sz = (int) s.size();
      int k = stoi(s.substr(1, sz - 2));
      while (k--) {
        int v;
        cin >> v;
        g[u].push_back(v);
      }
    }
    vector<int> pos(n);
    vector<int> low(n);
    vector<pair<int, int>> bridge;
    int stamp = 0;
    function<void(int, int)> dfs = [&](int u, int pv) {
      pos[u] = low[u] = ++stamp;
      for (const auto &v : g[u]) {
        if (pos[v] == 0) { // tree edge
          dfs(v, u);
          low[u] = min(low[u], low[v]);
          if (low[v] > pos[u]) {
            bridge.emplace_back(min(u, v), max(u, v));
          }
        } else {
          if (v != pv) { // back edge
            low[u] = min(low[u], pos[v]);
          }
        }
      }
    };
    for (int i = 0; i < n; i++) {
      if (pos[i] == 0) {
        dfs(i, i);
      }
    }
    sort(bridge.begin(), bridge.end());
    cout << (int) bridge.size() << " critical links" << '\n';
    for (int i = 0; i < (int) bridge.size(); i++) {
      cout << bridge[i].first << " - " << bridge[i].second << '\n';
    }
    cout << '\n';
  }
  return 0;
}
