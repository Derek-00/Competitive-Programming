/**
 *    author:  willy
 *    created: Fri, 01 Oct 2021 14:54:44 GMT
**/
#include <bits/stdc++.h>

using namespace std;

// problem URL: https://tioj.ck.tp.edu.tw/problems/1137

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    for (int i = 0; i < m; i++) {
      int a, b;
      cin >> a >> b;
      --a; --b;
      g[a].push_back(b);
      g[b].push_back(a);
    }
    vector<int> pos(n);
    vector<int> low(n);
    vector<bool> cutpoints(n, false);
    int smp = 0;
    function<void(int, int)> dfs = [&](int u, int pv) {
      pos[u] = low[u] = ++smp;
      int child = 0;
      for (const auto &v : g[u]) {
        if (pos[v] == 0) { // tree edge
          dfs(v, u);
          low[u] = min(low[u], low[v]);
          if (u != pv && low[v] >= pos[u]) {
            cutpoints[u] = true;
          } else {
            if (u == pv && ++child >= 2) {
              cutpoints[u] = true;
            }
          }
        } else {
          if (v != pv) { // back edge
            low[u] = min(low[u], pos[v]);
          }
        }
      }
    };
    dfs(0, 0);
    int cnt = accumulate(cutpoints.begin(), cutpoints.end(), 0);
    cout << cnt << '\n';
    if (cnt == 0) {
      cout << 0;
    } else {
      for (int i = 0; i < n; i++) {
        if (cutpoints[i]) {
          cout << i + 1 << " ";
        }
      }
    }
    cout << '\n';
  }
  return 0;
}
