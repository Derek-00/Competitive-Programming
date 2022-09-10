/**
 *    author:  wy
 *    created: Mon, 18 Jul 2022 12:37:16 GMT
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "C:\Users\wy\C++\solve\_debug\debug.h"
#else
#define debug(...) 42
#endif

const int N = 101;

int n, m, s;
int dist[N];
vector<int> g[N];

int main() {
  scanf("%d %d", &n, &m);
  scanf("%d", &s);
  for (int i = 0; i < m; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    g[a].push_back(b);
  }
  memset(dist, -1, sizeof(dist));
  vector<int> que(1, s);
  dist[s] = 0;
  int cnt = 0, d = 0;
  for (int b = 0; b < (int) que.size(); b++) {
    for (int v : g[que[b]]) {
      if (dist[v] == -1) {
        que.push_back(v);
        dist[v] = dist[que[b]] + 1;
        cnt += 1;
        d += dist[v];
      }
    }
  }
  printf("%d\n%d\n", cnt, d);
  return 0;
}
