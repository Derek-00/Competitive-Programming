/**
 *    author:  wy
 *    created: Thu, 21 Jul 2022 06:38:30 GMT
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "C:\Users\wy\C++\solve\_debug\debug.h"
#else
#define debug(...) 42
#endif

const int N = 510 * 510;

int n, m, k;
int cnt, mx;
int a[N], d[4];
int p[N], sz[N];

inline int get(int x) {
  return (x == p[x] ? x : (p[x] = get(p[x])));
}

bool Unite(int x, int y) {
  x = get(x);
  y = get(y);
  if (x != y) {
    if (sz[x] < sz[y]) {
      swap(x, y);
    }
    p[y] = x;
    sz[x] += sz[y];
    cnt -= 1;
    mx = max(mx, sz[x]);
    return true;
  }
  return false;
}

void Dfs(int v) {
  cnt += 1;
  for (int dir = 0; dir < 4; dir++) {
    if (a[v + d[dir]] == 1) {
      if (Unite(v, v + d[dir])) {
        Dfs(v + d[dir]);
      }
    }
  }
}

int main() {
  scanf("%d %d %d", &n, &m, &k);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      int id = i * (m + 2) + j;
      p[id] = id;
      sz[id] = 1;
      scanf("%d", &a[id]);
    }
  }
  m += 2;
  d[0] = 1; d[1] = -1;
  d[2] = m; d[3] = -m;
  int nm = (n + 1) * m;
  for (int i = m + 1; i < nm; i++) {
    if (a[i] == 1 && p[i] == i) {
      Dfs(i);
      mx = max(mx, sz[i]);
    }
  }
  long long sum_n = cnt;
  long long sum_mx = mx;
  while (k--) {
    int x, y;
    scanf("%d %d", &x, &y);
    int v = x * m + y;
    if (a[v] == 1) {
      continue;
    }
    a[v] = 1;
    cnt += 1;
    mx = max(mx, 1);
    for (int dir = 0; dir < 4; dir++) {
      if (a[v + d[dir]] == 1) {
        Unite(v, v + d[dir]);
      }
    }
    sum_n += cnt;
    sum_mx += mx;
  }
  printf("%lld\n%lld\n", sum_mx, sum_n);
  return 0;
}
