/**
 *    author:  willy
 *    created: Sat, 13 Nov 2021 14:53:52 GMT
**/
#include <bits/stdc++.h>

using namespace std;

class dsu {
 public:
  vector<int> p;
  int n;

  dsu(int _n) : n(_n) {
    p.resize(n);
    iota(p.begin(), p.end(), 0);
  }

  inline int get(int x) {
    return (x == p[x] ? x : (p[x] = get(p[x])));
  }

  inline bool unite(int x, int y) {
    x = get(x);
    y = get(y);
    if (x != y) {
      p[x] = y;
      return true;
    }
    return false;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  vector<vector<pair<int, int>>> g(n);
  for (int i = 0; i < n - 1; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    --u; --v;
    g[u].emplace_back(v, w);
    g[v].emplace_back(u, w);
  }
  vector<int> depth(n);
  vector<int> w(n);
  vector<int> p(n);
  function<void(int, int)> Dfs = [&](int v, int pr) {
    for (auto& node : g[v]) {
      int to = node.first;
      int cost = node.second;
      if (to == pr) {
        continue;
      }
      depth[to] = depth[v] + 1;
      w[to] = cost;
      p[to] = v;
      Dfs(to, v);
    }
  };
  Dfs(0, -1);
  vector<bool> vis(n, false);
  dsu d(n);
  while (q--) {
    int a, b;
    cin >> a >> b;
    --a; --b;
    int ans = 0;
    while (a != b) {
      if (depth[a] < depth[b]) {
        swap(a, b);
      }
      if (!vis[a]) {
        ans += w[a];
        d.unite(a, p[a]);
        vis[a] = true;
      }
      a = d.get(a);
    }
    cout << ans << '\n';
  }
  return 0;
}
