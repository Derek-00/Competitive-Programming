/**
 *    author:  willy
 *    created: Sat, 01 Jan 2022 16:02:12 GMT
**/
#include <bits/stdc++.h>

using namespace std;

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> g[i][j];
    }
  }
  vector<vector<int>> cnt(n, vector<int>(m));
  int amount = 0;
  function<void(int, int, int)> Dfs = [&](int x, int y, int tag) {
    amount += 1;
    g[x][y] = 0;
    cnt[x][y] = tag;
    for (int dir = 0; dir < 4; dir++) {
      int nx = x + dx[dir];
      int ny = y + dy[dir];
      if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
        if (g[nx][ny] == 1) {
          Dfs(nx, ny, tag);
        }
      }
    }
  };
  int k = 0;
  vector<int> rep(1, -1);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (g[i][j] == 1) {
        amount = 0;
        Dfs(i, j, ++k);
        rep.push_back(amount);
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (g[i][j] == 0) {
        int sum = 1;
        vector<bool> chosen((int) rep.size(), false);
        for (int dir = 0; dir < 4; dir++) {
          int nx = i + dx[dir];
          int ny = j + dy[dir];
          if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
            int id = cnt[nx][ny];
            if (id == 0) {
              continue;
            }
            if (!chosen[id]) {
              sum += rep[id];
              chosen[id] = true;
            }
          }
        }
        ans = max(ans, sum);
      }
    }
  }
  cout << ans << '\n';
  return 0;
}
