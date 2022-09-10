/**
 *    author:  willy
 *    created: Tue, 16 Nov 2021 07:44:00 GMT
**/
#include <bits/stdc++.h>

using namespace std;

template<typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

struct edge {
  int from;
  int to;
  int cost;
  int p;
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m, a, b, d;
  cin >> n >> m >> a >> b >> d;
  --a; --b;
  vector<edge> edges;
  vector<vector<int>> g(n);
  for (int i = 0; i < m; i++) {
    int n1, n2, c1, p1, c2, p2;
    cin >> n1 >> n2 >> c1 >> p1 >> c2 >> p2;
    --n1; --n2;
    int id = (int) edges.size();
    g[n1].push_back(id);
    edges.push_back({n1, n2, c1, p1});
    g[n2].push_back(id + 1);
    edges.push_back({n2, n1, c2, p2});
  }
  const int inf = (int) 1e9;
  auto dijkstra = [&](int s, int t, int d) {
    min_heap<pair<int, int>> pq;
    vector<int> dist(n, inf);
    dist[s] = 0;
    pq.emplace(dist[s], s);
    while (!pq.empty()) {
      int expected = pq.top().first;
      int i = pq.top().second;
      pq.pop();
      if (dist[i] != expected) {
        continue;
      }
      for (auto& id : g[i]) {
        auto& e = edges[id];
        int from = e.from;
        int to = e.to;
        int cost = e.cost + (d - 1) * e.p;
        if (dist[from] + cost < dist[to]) {
          dist[to] = dist[from] + cost;
          pq.emplace(dist[to], to);
        }
      }
    }
    return dist[t];
  };
  int dist0 = dijkstra(a, b, 1) + dijkstra(b, a, 1);
  int dist1 = dijkstra(a, b, d) + dijkstra(b, a, d);
  cout << min(dist0, dist1) << '\n';
  return 0;
}
