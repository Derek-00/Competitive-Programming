/**
 *    author:  willy
 *    created: Fri, 10 Sep 2021 13:31:16 GMT
**/
#include <bits/stdc++.h>

using namespace std;

const int dx[] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  while (cin >> n >> m) {
    if(n == 0 && m == 0) {
      break;
    }
    vector<vector<int>> g(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        char s;
        cin >> s;
        g[i][j] = (int) (s - '0');
      }
    }
    function<void(int, int)> dfs = [&](int x, int y) {
      g[x][y] = 0;
      for (int dir = 0; dir < 8; dir++) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
          if (g[nx][ny] == 1) {
            dfs(nx, ny);
          }
        }
      }
    };
    int ans = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (g[i][j] == 1) {
          ++ans;
          dfs(i, j);
        }
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
