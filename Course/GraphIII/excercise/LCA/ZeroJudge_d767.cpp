/**
 *    author:  willy
 *    created: Wed, 29 Sep 2021 13:43:02 GMT
**/
#include <bits/stdc++.h>

using namespace std;

// problem URL: https://zerojudge.tw/ShowProblem?problemid=d767

class lca_forest {
 public:
  struct edge {
    int from;
    int to;
  };

  vector<edge> edges;
  vector<vector<int>> g;
  int n;

  vector<int> pos;
  vector<int> end;
  vector<int> depth;
  vector<int> order;
  vector<int> pv;

  vector<vector<int>> pr;
  int h;

  lca_forest(int _n) : n(_n) {
    g.resize(n);
  }

  void add(int from, int to) {
    int id = (int) edges.size();
    g[from].push_back(id);
    edges.push_back({from, to});
  }

  void init() {
    pos = vector<int>(n, -1);
    end = vector<int>(n, -1);
    depth = vector<int>(n, -1);
    order.clear();
    pv = vector<int>(n, -1);
    pr = vector<vector<int>>(n);
  }

  void do_dfs(int v) {
    pos[v] = (int) order.size();
    order.push_back(v);
    for (const auto id : g[v]) {
      auto &e = edges[id];
      int to = e.from ^ e.to ^ v;
      depth[to] = depth[v] + 1;
      pv[to] = v;
      do_dfs(to);
    }
    end[v] = (int) order.size() - 1;
  }

  void dfs_all() {
    init();
    for (int v = 0; v < n; v++) {
      if (depth[v] == -1) {
        depth[v] = 0;
        pv[v] = -1;
        do_dfs(v);
      }
    }
  }

  void build() {
    int max_depth = -1;
    for (int i = 0; i < n; i++) {
      max_depth = max(max_depth, depth[i]);
    }
    h = 1;
    while ((1 << h) <= max_depth) {
      h++;
    }
    // init
    for (int i = 0; i < n; i++) {
      pr[i].resize(h);
      pr[i][0] = pv[i];
    }
    for (int j = 1; j < h; j++) {
      for (int i = 0; i < n; i++) {
        pr[i][j] = (pr[i][j - 1] == -1 ? -1 : pr[pr[i][j - 1]][j - 1]);
      }
    }
  }

  inline bool anc(int x, int y) {
    return (pos[x] <= pos[y] && end[y] <= end[x]);
  }

  inline int lca(int x, int y) {
    if (anc(x, y)) {
      return x;
    }
    if (anc(y, x)) {
      return y;
    }
    for (int j = h - 1; j >= 0; j--) {
      if (pr[x][j] != -1 && !anc(pr[x][j], y)) {
        x = pr[x][j];
      }
    }
    return pr[x][0];
  }

  inline int get(int a, int b, int c) {
    return depth[a] + depth[b] - 2 * depth[c];
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  lca_forest f(n);
  for (int i = 0; i < n; i++) {
    int x;
    while (cin >> x && x) {
      --x;
      f.add(i, x);
    }
  }
  f.dfs_all();
  f.build();
  while (q--) {
    int x, y;
    cin >> x >> y;
    --x; --y;
    int anc = f.lca(x, y);
    cout << anc + 1 << " " << f.get(x, y, anc) << '\n';
  }
  return 0;
}
