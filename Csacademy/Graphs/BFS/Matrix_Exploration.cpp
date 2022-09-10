/**
 *    author:  willy
 *    created: Wed, 29 Dec 2021 14:37:22 GMT
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  vector<string> g(n);
  for (int i = 0; i < n; i++) {
    cin >> g[i];
  }
  const int inf = (int) 1e9;
  vector<vector<int>> dist(n, vector<int>(m, inf));
  while (k--) {
    int x, y;
    cin >> x >> y;
    --x; --y;
    vector<array<int, 2>> que(1, {x, y});
    dist[x][y] = 0;
    for (int b = 0; b < (int) que.size(); b++) {
      for (int dx = -1; dx <= 1; dx++) {
        for (int dy = -1; dy <= 1; dy++) {
          if (abs(dx * dy) == 1) {
            continue;
          }
          int nx = que[b][0] + dx;
          int ny = que[b][1] + dy;
          if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
            if (g[nx][ny] == '.') {
              if (dist[nx][ny] > dist[que[b][0]][que[b][1]] + 1) {
                dist[nx][ny] = dist[que[b][0]][que[b][1]] + 1;
                que.push_back({nx, ny});
              }
            }
          }
        }
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (g[i][j] == '.') {
        ans += dist[i][j];        
      }
    }
  }
  cout << ans << '\n';
  return 0;
}
