/**
 *    author:  wy
 *    created: Mon, 17 Oct 2022 00:54:09 GMT
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "C:\Users\wy\C++\solve\_debug\debug.h"
#else
#define debug(...) 42
#endif

template <typename T>
class fenwick {
 public:
  vector<T> fenw;
  int n;

  fenwick(int _n) : n(_n) {
    fenw.resize(n);
  }

  void modify(int x, T v) {
    while (x < n) {
      fenw[x] += v;
      x |= (x + 1);
    }
  }

  T get(int x) {
    T v{};
    while (x >= 0) {
      v += fenw[x];
      x = (x & (x + 1)) - 1;
    }
    return v;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, s, t, w;
  cin >> n >> s >> t >> w;
  s -= 1;
  vector<vector<int>> g(n);
  vector<array<int, 2>> edges;
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    --u; --v;
    g[u].push_back(v);
    g[v].push_back(u);
    edges.push_back({u, v});
  }
  vector<int> pos(n), end(n);
  vector<int> pv(n, -1);
  vector<int> depth(n);
  int timer = 0;
  function<void(int, int)> Dfs = [&](int v, int pr) {
    pos[v] = timer++;
    for (int to : g[v]) {
      if (to == pr) {
        continue;
      }
      pv[to] = v;
      depth[to] = depth[v] + 1;
      Dfs(to, v);
    }
    end[v] = timer;
  };
  Dfs(s, -1);
  fenwick<int> fenw(n + 1);
  for (int qq = 0; qq < t + w; qq++) {
    int op;
    cin >> op;
    if (op == 1) {
      int x, y;
      cin >> x >> y;
      --y;
      int coeff = depth[y] - fenw.get(pos[y]);
      cout << (long long) coeff * x << '\n';
    }
    if (op == 2) {
      int z;
      cin >> z;
      auto e = edges[z - 1];
      int u = e[0];
      int v = e[1];
      // u to v
      if (pv[u] == v) {
        swap(u, v);
      }
      fenw.modify(pos[v], +1);
      fenw.modify(end[v], -1);
    }
  }
  return 0;
}
