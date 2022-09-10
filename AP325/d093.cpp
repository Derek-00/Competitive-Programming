/**
 *    author:  wy
 *    created: Mon, 18 Jul 2022 14:24:32 GMT
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "C:\Users\wy\C++\solve\_debug\debug.h"
#else
#define debug(...) 42
#endif

const int N = 510;

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};

int n, m;
char g[N][N];
int dist[N][N];

int main() {
  scanf("%d %d", &n, &m);
  memset(g, '1', sizeof(g));
  memset(dist, -1, sizeof(dist));
  for (int i = 1; i <= n; i++) {
    scanf("%s", &g[i][1]);
  }
  dist[1][1] = 0;
  vector<array<int, 2>> que(1, {1, 1});
  for (int b = 0; b < (int) que.size(); b++) {
    int x = que[b][0];
    int y = que[b][1];
    for (int dir = 0; dir < 4; dir++) {
      int nx = x + dx[dir];
      int ny = y + dy[dir];
      while (g[nx][ny] == '0') {
        if (dist[nx][ny] < 0) {
          dist[nx][ny] = dist[x][y] + 1;
          que.push_back({nx, ny});
        }
        nx += dx[dir];
        ny += dy[dir];
      }
    }
  }
  dist[n][m] -= (dist[n][m] > 0);
  printf("%d\n", dist[n][m]);
  return 0;
}
