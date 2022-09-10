/**
 *    author:  wy
 *    created: Tue, 19 Jul 2022 13:07:45 GMT
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "C:\Users\wy\C++\solve\_debug\debug.h"
#else
#define debug(...) 42
#endif

const int N = 10010;
const int inf = (int) 1e9;

int n, m, s, t;
int deg[N];
vector<pair<int, int>> g[N];
int dist[N][2];

int main() {
  scanf("%d %d", &n, &m);
  scanf("%d %d", &s, &t);
  for (int i = 0; i < m; i++) {
    int u, v, w;
    scanf("%d %d %d", &u, &v, &w);
    g[u].emplace_back(v, w);
    deg[v] += 1;
  }
  for (int i = 0; i < n; i++) {
    dist[i][0] = inf;
    dist[i][1] = -inf;
  }
  dist[s][0] = dist[s][1] = 0;
  vector<int> que;
  for (int i = 0; i < n; i++) {
    if (deg[i] == 0) {
      que.push_back(i);
    }
  }
  for (int b = 0; b < (int) que.size(); b++) {
    int u = que[b];
    for (auto p : g[u]) {
      int v = p.first;
      int w = p.second;
      if (dist[u][0] < inf) {
        dist[v][0] = min(dist[v][0], dist[u][0] + w);
        dist[v][1] = max(dist[v][1], dist[u][1] + w);
      }
      if (--deg[v] == 0) {
        que.push_back(v);
      }
    }
  }
  if (dist[t][0] == inf) {
    printf("No path\nNo path\n");
  } else {
    printf("%d\n%d\n", dist[t][0], dist[t][1]);
  }
  return 0;
}
