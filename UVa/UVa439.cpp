/**
 *    author:  willy
 *    created: Thu, 19 Aug 2021 02:04:02 GMT
**/
#include <bits/stdc++.h>

using namespace std;

const int dx[] = {-2, -2, -1, 1, 2, 2, -1, 1};
const int dy[] = {-1, 1, 2, 2, 1, -1, -2, -2};

const int board = 8;

inline pair<int, int> encode(string s) {
  return make_pair(s[0] - 'a', s[1] - '1');
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string x, y;
  while (cin >> x >> y) {
    auto s = encode(x);
    auto e = encode(y);
    vector<vector<int>> dist(board, vector<int>(board, -1));
    dist[s.first][s.second] = 0;
    vector<pair<int, int>> que(1, s);
    for (int b = 0; b < (int) que.size(); b++) {
      if (que[b] == e) {
        break;
      }
      for (int dir = 0; dir < board; dir++) {
        int nx = que[b].first + dx[dir];
        int ny = que[b].second + dy[dir];
        if (nx >= 0 && nx < board && ny >= 0 && ny < board) {
          if (dist[nx][ny] == -1) {
            dist[nx][ny] = dist[que[b].first][que[b].second] + 1;
            que.emplace_back(nx, ny);
          }
        }
      }
    }
    cout << "To get from " << x << " to " << y << " takes " << dist[e.first][e.second] << " knight moves." << '\n';
  }
  return 0;
}
