/**
 *    author:  willy
 *    created: Sat, 02 Oct 2021 10:25:38 GMT
**/
#include <bits/stdc++.h>

using namespace std;

// problem URL: https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=251

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  while (cin >> n && n) {
    cin.ignore();
    vector<vector<int>> g(n);
    string s;
    while (getline(cin, s)) {
      if (s == "0") {
        break;
      }
      stringstream ss(s);
      int u;
      ss >> u;
      --u;
      int v;
      while (ss >> v) {
        --v;
        g[u].push_back(v);
        g[v].push_back(u);
      }
    }
    vector<int> pos(n);
    vector<int> low(n);
    vector<bool> cutpoints(n, false);
    int stamp = 0;
    function<void(int, int)> dfs = [&](int u, int pr) {
      pos[u] = low[u] = ++stamp;
      int ch = 0;
      for (const auto &v : g[u]) {
        if (pos[v] == 0) { // tree edge
          dfs(v, u);
          low[u] = min(low[u], low[v]);
          if (u != pr && low[v] >= pos[u]) {
            cutpoints[u] = true;
          } else {
            if (u == pr && ++ch >= 2) {
              cutpoints[u] = true;
            }
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
    for (int i = 0; i < n; i++) {
      if (cutpoints[i]) {
        ++ans;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
