/**
 *    author:  wy
 *    created: Mon, 18 Jul 2022 13:53:02 GMT
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "C:\Users\wy\C++\solve\_debug\debug.h"
#else
#define debug(...) 42
#endif

const int N = 110;
const int inf = 0x3f3f3f3f;

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};

int n, m;
int a[N][N];
bool vis[N][N];

int Dfs(int x, int y) {
  vis[x][y] = true;
  int sum = a[x][y];
  int mx_i = 0, mx_j = 0;
  int mx = inf;
  for (int dir = 0; dir < 4; dir++) {
    int nx = x + dx[dir];
    int ny = y + dy[dir];
    if (a[nx][ny] < mx && !vis[nx][ny]) {
      mx_i = nx; mx_j = ny;
      mx = a[nx][ny];
    }
  }
  if (mx != inf) {
    sum += Dfs(mx_i, mx_j);
  }
  return sum;
}

int main() {
  scanf("%d %d", &n, &m);
  memset(a, inf, sizeof(a));
  int si = 0, sj = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      scanf("%d", &a[i][j]);
      if (a[i][j] < a[si][sj]) {
        si = i;
        sj = j;
      }
    }
  }
  printf("%d\n", Dfs(si, sj));
  return 0;
}
