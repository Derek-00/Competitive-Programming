/**
 *    author:  willy
 *    created: Sun, 29 Aug 2021 12:49:00 GMT
**/
#pragma g++ optimize("Ofast")
#pragma loop_opt(on)

#include <bits/stdc++.h>

using namespace std;

const int dx[] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> m >> n;
  vector<vector<char>> g(n, vector<char>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> g[i][j];
      if (g[i][j] != 'G' && g[i][j] != '-') {
        g[i][j] = ' ';
      }
    }
  }
  int green = 0;
  int ground = 0;
  function<void(int, int, char)> dfs = [&](int x, int y, char type) {
    for (int dir = 0; dir < 8; dir++) {
      int nx = x + dx[dir];
      int ny = y + dy[dir];
      if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
        if (g[nx][ny] == type) {
          g[nx][ny] = ' ';
          dfs(nx, ny, type);
        }
      }
    }
  };
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (g[i][j] == '-') {
        ground += 1;
        g[i][j] = ' ';
        dfs(i, j, '-');
      }
      if (g[i][j] == 'G') {
        green += 1;
        g[i][j] = ' ';
        dfs(i, j, 'G');
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      assert(isspace(g[i][j]));
    }
  }
  cout << green << " " << ground << '\n';
  return 0;
}
