/**
 *    author:  willy
 *    created: Tue, 05 Oct 2021 11:05:44 GMT
**/
#include <bits/stdc++.h>

using namespace std;

class graph {
 public:
  struct edge {
    int from;
    int to;
  };

  vector<edge> edges;
  vector<vector<int>> g;
  int n;

  graph(int _n) : n(_n) {
    g.resize(n);
  }

  void add(int from, int to) {
    int id = (int) edges.size();
    g[from].push_back(id);
    edges.push_back({from, to});
  }
};

int find_scc(const graph& g) {
  vector<int> order;
  vector<bool> was(g.n, false);
  function<void(int)> dfs1 = [&](int v) {
    was[v] = true;
    for (const auto &id : g.g[v]) {
      int to = g.edges[id].to;
      if (!was[to]) {
        dfs1(to);
      }
    }
    order.push_back(v);
  };
  for (int i = 0; i < g.n; i++) {
    if (!was[i]) {
      dfs1(i);
    }
  }
  vector<int> c(g.n, -1);
  function<void(int)> dfs2 = [&](int v) {
    for (const auto &id : g.g[v]) {
      int to = g.edges[id].to;
      if (c[to] == -1) {
        c[to] = c[v];
        dfs2(to);
      }
    }
  };
  int cnt = 0;
  for (int i = g.n - 1; i >= 0; i--) {
    int id = order[i];
    if (c[id] == -1) {
      c[id] = cnt++;
      dfs2(id);
    }
  }
  return cnt;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  graph g(n);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    --a; --b;
    g.add(a, b);
  }
  int ans = find_scc(g);
  cout << ans << '\n';
  return 0;
}
