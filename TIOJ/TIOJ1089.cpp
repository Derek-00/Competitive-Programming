/**
 *    author:  willy
 *    created: Tue, 21 Dec 2021 15:27:05 GMT
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<vector<int>> g(n);
  for (int i = 0; i < k; i++) {
    int r, c;
    cin >> r >> c;
    --r; --c;
    g[r].push_back(c);
  }
  int ans = 0;
  vector<bool> vis(n);
  vector<int> p(n, -1);
  function<bool(int)> dfs = [&](int v) {
    for (auto& to : g[v]) {
      if (!vis[to]) {
        vis[to] = true;
        if (p[to] == -1 || dfs(p[to])) {
          p[to] = v;
          return true;
        }
      }
    }
    return false;
  };
  for (int i = 0; i < n; i++) {
    fill(vis.begin(), vis.end(), false);
    if (dfs(i)) {
      ans += 1;
    }
  }
  cout << ans << '\n';
  return 0;
}
