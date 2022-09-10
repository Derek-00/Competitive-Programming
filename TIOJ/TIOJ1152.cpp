/**
 *    author:  willy
 *    created: Fri, 27 Aug 2021 09:37:16 GMT
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<vector<int>> g(n);
  for (int i = 0; i < n; i++) {
    int x;
    while (cin >> x && ~x) {
      g[i].push_back(x);
    }
  }
  function<pair<int, int>(int)> dfs = [&](int u) {
    vector<int> depth(1, 0);
    int ans = 0;
    for (const auto &v : g[u]) {
      auto p = dfs(v);
      ans = max(ans, p.first);
      depth.push_back(p.second + 1);
    }
    sort(depth.rbegin(), depth.rend());
    if (depth.size() >= 2) {
      ans = max(ans, depth[0] + depth[1]);
    }
    return make_pair(ans, depth[0]);
  };
  cout << dfs(0).first << '\n';
  return 0;
}
