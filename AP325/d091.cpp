/**
 *    author:  wy
 *    created: Mon, 18 Jul 2022 13:46:56 GMT
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "C:\Users\wy\C++\solve\_debug\debug.h"
#else
#define debug(...) 42
#endif

const int N = 50010;

int n, m;
int w[N];
vector<int> g[N];
bool vis[N];

int Dfs(int u) {
  int sum = w[u];
  vis[u] = true;
  for (int v : g[u]) {
    if (!vis[v]) {
      sum += Dfs(v);
    }
  }
  return sum;
}

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%d", &w[i]);
  }
  for (int i = 0; i < m; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    g[a].push_back(b);
    g[b].push_back(a);
  }
  int ans = 0;
  for (int u = 0; u < n; u++) {
    if (!vis[u]) {
      ans = max(ans, Dfs(u));
    }
  }
  printf("%d\n", ans);
  return 0;
}
