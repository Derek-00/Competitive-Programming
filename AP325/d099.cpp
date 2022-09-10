/**
 *    author:  wy
 *    created: Wed, 20 Jul 2022 11:11:55 GMT
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "C:\Users\wy\C++\solve\_debug\debug.h"
#else
#define debug(...) 42
#endif

const int N = 10010;
const int inf = 0x3f3f3f3f;

int n, m;
int w[N], deg[N];
int dist[N][2];
vector<int> g[N];
vector<int> top;

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &w[i]);
  }
  for (int i = 0; i < m; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    g[u].push_back(v);
    deg[v] += 1;
  }
  for (int i = 1; i <= n; i++) {
    dist[i][0] = -inf;
    dist[i][1] = inf;
  }
  for (int i = 1; i <= n; i++) {
    if (deg[i] == 0) {
      top.push_back(i);
      dist[i][0] = w[i];
    }
  }
  for (int b = 0; b < (int) top.size(); b++) {
    int u = top[b];
    for (int v : g[u]) {
      dist[v][0] = max(dist[v][0], dist[u][0] + w[v]);
      if (--deg[v] == 0) {
        top.push_back(v);
      }
    }
  }
  int mx = -inf;
  for (int i = 1; i <= n; i++) {
    mx = max(mx, dist[i][0]);
  }
  printf("%d\n", mx);
  for (int i = 1; i <= n; i++) {
    if (dist[i][0] == mx) {
      dist[i][1] = dist[i][0];
      top.push_back(i);
    }
  }
  for (int i = (int) top.size() - 1; i >= 0; i--) {
    int u = top[i];
    for (int v : g[u]) {
      dist[u][1] = min(dist[u][1], dist[v][1] - w[v]);
    }
  }
  bool IsFirst = true;
  for (int i = 1; i <= n; i++) {
    if (dist[i][0] == dist[i][1]) {
      if (!IsFirst) {
        putchar(' ');
      }
      IsFirst = false;
      printf("%d", i);
    }
  }
  return 0;
}
