/**
 *    author:  willy
 *    created: Thu, 30 Dec 2021 10:39:26 GMT
**/
#include <bits/stdc++.h>

using namespace std;

struct edge {
  int from;
  int to;
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  vector<edge> edges;
  vector<vector<int>> g(n);
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    --a; --b;
    int id = (int) edges.size();
    g[a].push_back(id);
    g[b].push_back(id);
    edges.push_back({a, b});
  }
  vector<int> pos(n, -1);
  vector<int> end(n, -1);
  vector<int> pv(n, -1);
  vector<int> depth(n, -1);
  int order = 0;
  function<void(int)> dfs = [&](int v) {
    pos[v] = order++;
    for (auto& id : g[v]) {
      auto& e = edges[id];
      int to = e.from ^ e.to ^ v;
      if (pos[to] != -1) {
        continue;
      }
      depth[to] = depth[v] + 1;
      pv[to] = v;
      dfs(to);
    }
    end[v] = order++;
  };
  pv[0] = -1;
  depth[0] = 0;
  dfs(0);
  int max_depth = *max_element(depth.begin(), depth.end());
  int h = 1;
  while ((1 << h) <= max_depth) {
    h += 1;
  }
  vector<vector<int>> pr(n, vector<int>(h));
  for (int i = 0; i < n; i++) {
    pr[i][0] = pv[i];
  }
  for (int j = 1; j < h; j++) {
    for (int i = 0; i < n; i++) {
      pr[i][j] = (pr[i][j - 1] == -1 ? -1 : pr[pr[i][j - 1]][j - 1]);
    }
  }
  auto Anc = [&](int x, int y) {
    return (pos[x] <= pos[y] && end[y] <= end[x]);
  };
  auto lca = [&](int x, int y) {
    if (Anc(x, y)) {
      return x;
    }
    if (Anc(y, x)) {
      return y;
    }
    for (int j = h - 1; j >= 0; j--) {
      if (pr[x][j] != -1 && !Anc(pr[x][j], y)) {
        x = pr[x][j];
      }
    }
    return pr[x][0];
  };
  auto Dist = [&](int a, int b, int c, int& anc) {
    anc = lca(a, b);
    int dist = 0;
    for (auto& v : {a, b, c}) {
      dist += depth[anc] + depth[v] - 2 * depth[lca(anc, v)];
    }
    return dist;
  };
  while (q--) {
    int a, b, c;
    cin >> a >> b >> c;
    --a; --b; --c;
    int anc = -1, dist = -1;
    auto Update = [&](int x, int y, int z) {
      int new_anc = -1;
      int new_dist = Dist(x, y, z, new_anc);
      if (dist == -1 || dist > new_dist) {
        dist = new_dist;
        anc = new_anc;
      }
    };
    Update(a, b, c);
    Update(b, c, a);
    Update(a, c, b);
    cout << anc + 1 << " " << dist << '\n';
  }
  return 0;
}
