/**
 *    author:  wy
 *    created: Tue, 19 Jul 2022 13:31:20 GMT
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "C:\Users\wy\C++\solve\_debug\debug.h"
#else
#define debug(...) 42
#endif

template<typename T>
using min_heap = priority_queue<pair<T, T>, vector<pair<T, T>>, greater<pair<T, T>>>;

const int N = 10010;
const int inf = 0x3f3f3f3f;

int n, m;
int dist[N];
vector<pair<int, int>> g[N];

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; i++) {
    int u, v, w;
    scanf("%d %d %d", &u, &v, &w);
    g[u].emplace_back(v, w);
    g[v].emplace_back(u, w);
  }
  memset(dist, inf, sizeof(dist));
  min_heap<int> pq;
  dist[0] = 0;
  pq.emplace(dist[0], 0);
  while (!pq.empty()) {
    int expected = pq.top().first;
    int i = pq.top().second;
    pq.pop();
    if (dist[i] != expected) {
      continue;
    }
    for (auto p : g[i]) {
      int to = p.first;
      int cost = p.second;
      if (dist[to] > dist[i] + cost) {
        dist[to] = dist[i] + cost;
        pq.emplace(dist[to], to);
      }
    }
  }
  int mx = -inf;
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (dist[i] < inf) {
      mx = max(mx, dist[i]);
    } else {
      cnt += 1;
    }
  }
  printf("%d\n%d", mx, cnt);
  return 0;
}
