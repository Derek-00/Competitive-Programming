/**
 *    author:  wy
 *    created: Wed, 20 Jul 2022 13:57:05 GMT
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "C:\Users\wy\C++\solve\_debug\debug.h"
#else
#define debug(...) 42
#endif

const int N = 10010;

int n, m;
int color[N];
vector<int> g[N];

bool Dfs(int u) {
  for (int v : g[u]) {
    if (color[v] == -1) {
      color[v] = color[u] ^ 1;
      if (!Dfs(v)) {
        return false;
      }
    } else {
      if (color[v] ^ color[u] == 0) {
        return false;
      }
    }
  }
  return true;
}

int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
      g[i].clear();
      color[i] = -1;
    }
    for (int i = 0; i < m; i++) {
      int u, v;
      scanf("%d %d", &u, &v);
      g[u].push_back(v);
      g[v].push_back(u);
    }
    bool can = true;
    for (int i = 0; i < n; i++) {
      if (color[i] == -1) {
        color[i] = 0;
        can &= Dfs(i);
      }
    }
    printf(can ? "yes\n" : "no\n");
  }
  return 0;
}
