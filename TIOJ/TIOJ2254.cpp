/**
 *    author:  wy
 *    created: Mon, 17 Oct 2022 02:48:45 GMT
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "C:\Users\wy\C++\solve\_debug\debug.h"
#else
#define debug(...) 42
#endif

struct edge {
  int from;
  int to;
  int cost;
};

vector<edge> edges;

inline bool Valid(edge e, int p) {
  return e.cost <= p;
}

vector<int> toposort(const vector<vector<int>>& g, int p) {
  const int n = (int) g.size();
  vector<int> deg(n);
  for (int i = 0; i < n; i++) {
    for (int id : g[i]) {
      auto e = edges[id];
      if (!Valid(e, p)) {
        deg[e.to] += 1;
      }
    }
  }
  vector<int> x;
  for (int i = 0; i < n; i++) {
    if (deg[i] == 0) {
      x.push_back(i);
    }
  }
  for (int ptr = 0; ptr < (int) x.size(); ptr++) {
    for (int id : g[x[ptr]]) {
      auto e = edges[id];
      if (!Valid(e, p)) {
        if (--deg[e.to] == 0) {
          x.push_back(e.to);
        }
      }
    }
  }
  if (x.size() != n) {
    return vector<int>();
  }
  return x;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n);
  int mx_ws = 0;
  for (int i = 0; i < m; i++) {
    int u, v, c;
    cin >> u >> v >> c;
    --u; --v;
    mx_ws = max(mx_ws, c);
    int id = (int) edges.size();
    g[u].push_back(id);
    edges.push_back({u, v, c});
  }
  vector<int> ans;
  auto Can = [&](int p) {
    auto tp = toposort(g, p);
    if (tp.empty()) {
      return false;
    }
    ans = tp;
    return true;
  };
  int low = -1;
  int high = mx_ws + 1;
  while (low < high) {
    int mid = (low + high + 1) >> 1;
    if (Can(mid)) {
      high = mid - 1;
    } else {
      low = mid;
    }
  }
  cout << low + 1 << " ";
  low += 1;
  vector<int> order(n);
  for (int i = 0; i < n; i++) {
    order[ans[i]] = i;
  }
  vector<int> es;
  for (int i = 0; i < n; i++) {
    int x = ans[i];
    for (int id : g[x]) {
      auto e = edges[id];
      if (Valid(e, low)) {
        if (order[e.from] > order[e.to]) {
          es.push_back(id);
        }
      }
    }
  }
  cout << (int) es.size() << '\n';
  for (int i = 0; i < (int) es.size(); i++) {
    cout << es[i] + 1 << '\n';
  }
  return 0;
}
