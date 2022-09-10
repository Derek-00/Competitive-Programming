/**
 *    author:  willy
 *    created: Sun, 01 Aug 2021 10:03:10 GMT
**/
#include <iostream>

using namespace std;

const int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};

const int N = 105;
int n, m;
char g[N][N];
bool vis[N][N];

void dfs(int x, int y) {
  if (vis[x][y]) {
    return;
  }
  vis[x][y] = true;
  for (int i = 0; i < 8; i++) {
    int nx = x + dx[i];
    int ny = y + dy[i];
    if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
      if (g[nx][ny] == 'W') {
        dfs(nx, ny);
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> g[i][j];
    }
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (g[i][j] == 'W' && !vis[i][j]) {
        dfs(i, j);
        ++ans;
      }
    }
  }
  cout << ans << '\n';
  return 0;
}
