/**
 *    author:  willy
 *    created: Tue, 03 Aug 2021 09:42:38 GMT
**/
#include <bits/stdc++.h>

using namespace std;

struct edge {
  int from;
  int to;
  int cost;
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  while (cin >> n >> m) {
    vector<edge> edges;
    vector<vector<int>> g(n);
    for (int i = 0; i < m; i++) {
      int a, b, c;
      cin >> a >> b >> c;
      --a; --b;
      assert(a >= 0 && a < n && b >= 0 && b < n);
      int id = (int) edges.size();
      g[a].push_back(id);
      g[b].push_back(id);
      edges.push_back({a, b, c});
    }
    vector<int> ans;
    vector<int> dist(n);
    { // reverse bfs
      vector<bool> vis(n);
      vis[n - 1] = true;
      vector<int> que(1, n - 1);
      for (int b = 0; b < (int) que.size(); b++) {
        int from = que[b];
        for (const int id : g[from]) {
          auto &e = edges[id];
          int to = e.from ^ e.to ^ from;
          if (!vis[to]) {
            dist[to] = dist[from] + 1;
            vis[to] = true;
            que.push_back(to);
          }
        }
      }
    }
    { // forward bfs to construct the path
      vector<bool> vis(n);
      vis[0] = true;
      vector<int> nxt(1, 0);
      for (int i = 0; i < dist[0]; i++) {
        int mn = (int) 1e9;
        for (int j = 0; j < (int) nxt.size(); j++) {
          int from = nxt[j];
          for (const int id : g[from]) {
            auto &e = edges[id];
            int to = e.from ^ e.to ^ from;
            int cost = e.cost;
            if (dist[from] == dist[to] + 1) {
              mn = min(mn, cost);
            }
          }
        }
        ans.push_back(mn);
        vector<int> nxt2;
        for (int j = 0; j < (int) nxt.size(); j++) {
          int from = nxt[j];
          for (const int id : g[from]) {
            auto &e = edges[id];
            int to = e.from ^ e.to ^ from;
            int cost = e.cost;
            if (dist[from] == dist[to] + 1 && !vis[to] && cost == mn) {
              vis[to] = true;
              nxt2.push_back(to);
            }
          }
        }
        nxt = nxt2;
      }
    }
    cout << (int) ans.size() << '\n';
    for (int i = 0; i < (int) ans.size(); i++) {
      if (i > 0) {
        cout << " ";
      }
      cout << ans[i];
    }
    cout << '\n';
  }
  return 0;
}
