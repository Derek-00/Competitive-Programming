/**
 *    author:  willy
 *    created: Mon, 09 Aug 2021 08:35:18 GMT
**/
#include <bits/stdc++.h>

using namespace std;

#define int long long

struct edge {
  int from;
  int to;
  int cost;
};

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m;
    cin >> n >> m;
    int s, t;
    cin >> s >> t;
    vector<edge> edges;
    vector<vector<int>> g(n);
    for (int i = 0; i < m; i++) {
      int a, b, k;
      cin >> a >> b >> k;
      int id = (int) edges.size();
      g[a].push_back(id);
      edges.push_back({a, b, k});
    }
    const int inf = (int) 1e18;
    vector<int> new_dist(n, inf);
    vector<int> dist(n, inf);
    dist[s] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.emplace(dist[s], s);
    while (!pq.empty()) {
      int expected = pq.top().first;
      int i = pq.top().second;
      pq.pop();
      if (new_dist[i] < expected) {
        continue;
      }
      for (const int id : g[i]) {
        auto &e = edges[id];
        int to = e.from ^ e.to ^ i;
        int cost = e.cost;
        int len = expected + cost;
        if (len < dist[to]) {
          swap(len, dist[to]);
          pq.emplace(dist[to], to);
        }
        if (len < new_dist[to] && len != dist[to]) {
          new_dist[to] = len;
          pq.emplace(new_dist[to], to);
        }
      }
    }
    cout << new_dist[t] - dist[t] << '\n';
  }
  return 0;
}
