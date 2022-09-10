/**
 *    author:  willy
 *    created: Mon, 09 Aug 2021 14:44:36 GMT
**/
#include <bits/stdc++.h>

using namespace std;

const int dx[] = {-1, 1, 0, 0, 0, 0};
const int dy[] = {0, 0, -1, 1, 0, 0};
const int dz[] = {0, 0, 0, 0, -1, 1};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int x, y, z;
  cin >> x >> y >> z;
  vector<vector<vector<int>>> g(x, vector<vector<int>>(y, vector<int>(z)));
  for (int k = 0; k < z; k++) {
    for (int j = 0; j < y; j++) {
      for (int i = 0; i < x; i++) {
        cin >> g[i][j][k];
      }
    }
  }
  if (g[0][0][0] == 1) {
    cout << "no route" << '\n';
    return 0;
  }
  vector<vector<vector<tuple<int, int, int>>>> pr(x, vector<vector<tuple<int, int, int>>>(y, vector<tuple<int, int, int>>(z)));
  vector<vector<vector<int>>> dist(x, vector<vector<int>>(y, vector<int>(z, -1)));
  dist[0][0][0] = 0;
  vector<tuple<int, int, int>> que(1, make_tuple(0, 0, 0));
  for (int b = 0; b < (int) que.size(); b++) {
    auto cur = que[b];
    for (int dir = 0; dir < 6; dir++) {
      int nx = get<0>(cur) + dx[dir];
      int ny = get<1>(cur) + dy[dir];
      int nz = get<2>(cur) + dz[dir];
      if (nx >= 0 && nx < x && ny >= 0 && ny < y && nz >= 0 && nz < z) {
        if (dist[nx][ny][nz] == -1 && g[nx][ny][nz] == 0) {
          dist[nx][ny][nz] = dist[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
          pr[nx][ny][nz] = make_tuple(get<0>(cur), get<1>(cur), get<2>(cur));
          que.emplace_back(nx, ny, nz);
        }
      }
    }
  }
  int d = dist[x - 1][y - 1][z - 1];
  if (d == -1) {
    cout << "no route" << '\n';
    return 0;
  }
  vector<tuple<int, int, int>> ans(1, make_tuple(x - 1, y - 1, z - 1));
  for (int i = 0; i < d; i++) {
    auto cur = ans.back();
    ans.emplace_back(pr[get<0>(cur)][get<1>(cur)][get<2>(cur)]);
  }
  reverse(ans.begin(), ans.end());
  for (int i = 0; i < (int) ans.size(); i++) {
    if (i > 0) {
      cout << "->";
    }
    cout << '(' << get<0>(ans[i]) + 1 << ',' << get<1>(ans[i]) + 1 << ',' << get<2>(ans[i]) + 1 << ')';
  }
  return 0;
}
