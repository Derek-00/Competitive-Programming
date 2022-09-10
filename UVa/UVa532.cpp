#include <bits/stdc++.h>

using namespace std;

const int dx[] = {-1, 1, 0, 0, 0, 0};
const int dy[] = {0, 0, -1, 1, 0, 0};
const int dz[] = {0, 0, 0, 0, -1, 1};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int l, r, c;
  while (cin >> l >> r >> c) {
    if (l == 0) break;
    vector<vector<vector<char>>> g(l, vector<vector<char>>(r, vector<char>(c)));
    vector<vector<vector<int>>> dist(l, vector<vector<int>>(r, vector<int>(c, -1)));
    queue<tuple<int, int, int>> q;
    tuple<int, int, int> end;
    for (int i = 0; i < l; i++) {
      for (int j = 0; j < r; j++) {
        for (int k = 0; k < c; k++) {
          cin >> g[i][j][k];
          if (g[i][j][k] == 'S') {
            q.emplace(i, j, k);
            dist[i][j][k] = 0;
          }
          if (g[i][j][k] == 'E') {
            end = make_tuple(i, j, k);
          }
        }
      }
    }
    while (!q.empty()) {
      auto cur = q.front(); q.pop();
      if (g[get<0>(cur)][get<1>(cur)][get<2>(cur)] == 'E') {
        break;
      }
      for (int i = 0; i < 6; i++) {
        int nx = get<1>(cur) + dx[i];
        int ny = get<2>(cur) + dy[i];
        int nz = get<0>(cur) + dz[i];
        if (nx < 0 || nx >= r || ny < 0 || ny >= c || nz < 0 || nz >= l) {
          continue;
        }
        if (dist[nz][nx][ny] == -1 && g[nz][nx][ny] != '#') {
          dist[nz][nx][ny] = dist[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
          q.emplace(nz, nx, ny);
        }
      }
    }
    if (dist[get<0>(end)][get<1>(end)][get<2>(end)] != -1) {
      cout << "Escaped in " << dist[get<0>(end)][get<1>(end)][get<2>(end)] << " minute(s).\n";
    } else {
      cout << "Trapped!\n";
    }
  }
  return 0;
}
