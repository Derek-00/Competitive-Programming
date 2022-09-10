/**
 *    author:  wy
 *    created: Thu, 21 Jul 2022 14:48:08 GMT
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "C:\Users\wy\C++\solve\_debug\debug.h"
#else
#define debug(...) 42
#endif

const int N = 50010;

int n;
int sum;
vector<int> path;
vector<int> g[N];

void Dfs(int u, int p) {
  path.push_back(u);
  for (int v : g[u]) {
    if (v == p) {
      continue;
    }
    Dfs(v, u);
    path.push_back(u);
  }
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n - 1; i++) {
    int a, b, w;
    scanf("%d %d %d", &a, &b, &w);
    g[a].push_back(b);
    g[b].push_back(a);
    sum += w;
  }
  for (int i = 0; i < n; i++) {
    sort(g[i].begin(), g[i].end());
  }
  Dfs(0, -1);
  printf("%d\n", sum + sum);
  for (int i = 0; i < (int) path.size(); i++) {
    if (i > 0) {
      putchar(' ');
    }
    printf("%d", path[i]);
  }
  return 0;
}
