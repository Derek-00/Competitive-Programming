/**
 *    author:  wy
 *    created: Sun, 16 Oct 2022 08:41:50 GMT
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "C:\Users\wy\C++\solve\_debug\debug.h"
#else
#define debug(...) 42
#endif

#define int long long

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

struct edge {
  int from;
  int to;
  int cost;

  inline bool operator < (const edge& rhs) const {
    return cost < rhs.cost;
  }
};

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<edge> edges(m);
  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    --a; --b;
    edges[i] = {a, b, c};
  }
  sort(edges.begin(), edges.end());
  vector<vector<pair<int, int>>> g(n);
  vector<edge> new_edges;
  int weights = 0, cnt = 0;
  dsu d(n);
  for (int i = 0; i < m; i++) {
    int u = edges[i].from;
    int v = edges[i].to;
    int cost = edges[i].cost;
    if (d.unite(u, v)) {
      weights += cost;
      cnt += 1;
      g[u].emplace_back(v, cost);
      g[v].emplace_back(u, cost);
    } else {
      new_edges.push_back(edges[i]);
    }
  }
  if (cnt != n - 1) {
    cout << "-1 -1" << '\n';
    return 0;
  }
  cout << weights << " ";
  vector<int> pos(n), ends(n);
  vector<int> depth(n);
  vector<int> pv(n, -1);
  vector<int> pv_w(n, -1);
  int mx_depth = 1;
  int timer = 0;
  function<void(int, int)> Dfs = [&](int v, int pr) {
    pos[v] = timer++;
    for (auto p : g[v]) {
      int to = p.first;
      int w = p.second;
      if (to == pr) {
        continue;
      }
      pv[to] = v;
      pv_w[to] = w;
      depth[to] = depth[v] + 1;
      mx_depth = max(mx_depth, depth[to]);
      Dfs(to, v);
    }
    ends[v] = timer;
  };
  Dfs(0, -1);
  int h = 1;
  while ((1 << h) <= mx_depth) {
    h += 1;
  }
  vector<vector<int>> pr(n, vector<int>(h));
  vector<vector<int>> pw(n, vector<int>(h));
  for (int i = 0; i < n; i++) {
    pr[i][0] = pv[i];
    pw[i][0] = pv_w[i];
  }
  for (int j = 1; j < h; j++) {
    for (int i = 0; i < n; i++) {
      pr[i][j] = (pr[i][j - 1] == -1 ? -1 : pr[pr[i][j - 1]][j - 1]);
      pw[i][j] = max(pw[i][j - 1], (pr[i][j - 1] == -1 ? 0 : pw[pr[i][j - 1]][j - 1]));
    }
  }
  auto anc = [&](int x, int y) {
    return (pos[x] <= pos[y] && ends[y] <= ends[x]);
  };
  auto Calc = [&](int x, int y) {
    if (x == y) {
      return 0LL;
    }
    int diff = depth[y] - depth[x];
    int bits = 31 - __builtin_clz(diff);
    int mx = 0;
    for (int j = 0; j <= bits; j++) {
      if ((1 << j) & diff) {
        mx = max(mx, pw[y][j]);
        y = pr[y][j];
      }
    }
    assert(x == y);
    return mx;
  };
  auto Lca = [&](int x, int y) {
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
  };
  auto Get = [&](int x, int y) {
    int lca = Lca(x, y);
    return max(Calc(lca, x), Calc(lca, y));
  };
  int ans = (int) 9e18;
  for (int i = 0; i < (int) new_edges.size(); i++) {
    auto e = new_edges[i];
    int u = e.from;
    int v = e.to;
    int cost = e.cost;
    int new_weights = weights + cost - Get(u, v);
    if (new_weights != weights && new_weights < ans) {
      ans = new_weights;
    }
  }
  cout << (ans == (int) 9e18 ? -1 : ans) << '\n';
  return 0;
}
