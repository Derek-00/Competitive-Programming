/**
 *    author:  willy
 *    created: Sat, 02 Oct 2021 12:07:16 GMT
**/
#include <bits/stdc++.h>

using namespace std;

// problem URL: https://open.kattis.com/problems/intercept

#define int long long

using min_heap = priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>;

struct edge {
  int from;
  int to;
  int cost;
};

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<edge> edges;
  vector<vector<int>> g(n);
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    int id = (int) edges.size();
    g[u].push_back(id);
    g[v].push_back(id);
    edges.push_back({u, v, w});
  }
  int s, t;
  cin >> s >> t;
  auto dijkstra = [&](int start) {
    const int inf = (int) 1e18;
    vector<int> dist(n, inf);
    dist[start] = 0;
    min_heap pq;
    pq.emplace(dist[start], start);
    while (!pq.empty()) {
      int expected = pq.top().first;
      int from = pq.top().second;
      pq.pop();
      if (dist[from] != expected) {
        continue;
      }
      for (const auto &id : g[from]) {
        auto &e = edges[id];
        int to = e.from ^ e.to ^ from;
        if (dist[from] + e.cost < dist[to]) {
          dist[to] = dist[from] + e.cost;
          pq.emplace(dist[to], to);
        }
      }
    }
    return dist;
  };
  auto dist = dijkstra(s);
  auto rdist = dijkstra(t);
  vector<bool> vis(n, false);
  vector<int> ans;
  min_heap pq;
  pq.emplace(0, s);
  while (!pq.empty()) {
    int from = pq.top().second;
    pq.pop();
    if (pq.empty()) {
      ans.push_back(from);
    }
    for (const auto &id : g[from]) {
      auto &e = edges[id];
      int to = e.from ^ e.to ^ from;
      if (vis[to]) {
        continue;
      }
      if (dist[t] - dist[from] == e.cost + rdist[to]) {
        pq.emplace(dist[to], to);
        vis[to] = true;
      }
    }
  }
  sort(ans.begin(), ans.end());
  for (int i = 0; i < (int) ans.size(); i++) {
    if (i > 0) {
      cout << " ";
    }
    cout << ans[i];
  }
  return 0;
}
