/**
 *    author:  willy
 *    created: Tue, 21 Sep 2021 06:38:36 GMT
**/
#include <bits/stdc++.h>

using namespace std;

const int dx[] = {-1, 0, 1, 0, 0};
const int dy[] = {0, -1, 0, 1, 0};

inline bool conflict(int a0, int b0, int a1, int b1) {
  return (a1 == b1 || (a0 == b1 && b0 == a1));
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int w, h, n;
  while (cin >> w >> h >> n && n) {
    string foo = "";
    getline(cin, foo);
    vector<string> maze(h);
    vector<vector<int>> id(h, vector<int>(w));
    vector<pair<int, int>> c;
    array<int, 3> s;
    array<int, 3> t;
    int cnt = 0;
    for (int i = 0; i < h; i++) {
      getline(cin, maze[i]);
    }
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        if (maze[i][j] != '#') {
          id[i][j] = cnt;
          c.emplace_back(i, j);
          if (islower(maze[i][j])) {
            s[(int) (maze[i][j] - 'a')] = cnt;
          } else {
            if (isupper(maze[i][j])) {
              t[(int) (maze[i][j] - 'A')] = cnt;
            }
          }
          cnt += 1;
        }
      }
    }
    // make a new graph without '#'
    vector<vector<int>> g(cnt);
    for (int i = 0; i < cnt; i++) {
      for (int dir = 0; dir < 5; dir++) {
        int nx = c[i].first + dx[dir];
        int ny = c[i].second + dy[dir];
        if (maze[nx][ny] != '#') {
          g[i].push_back(id[nx][ny]);
        }
      }
    }
    if (n <= 2) {
      g.push_back({cnt});
      s[2] = t[2] = cnt++;
    }
    if (n <= 1) {
      g.push_back({cnt});
      s[1] = t[1] = cnt++;
    }
    // do bfs...
    vector<vector<vector<int>>> dist(cnt, vector<vector<int>>(cnt, vector<int>(cnt, -1)));
    queue<array<int, 3>> q;
    q.push(s);
    dist[s[0]][s[1]][s[2]] = 0;
    while (!q.empty()) {
      auto u = q.front();
      q.pop();
      if (u == t) {
        cout << dist[u[0]][u[1]][u[2]] << '\n';
        break;
      }
      for (int i = 0; i < (int) g[u[0]].size(); i++) {
        int na = g[u[0]][i];
        for (int j = 0; j < (int) g[u[1]].size(); j++) {
          int nb = g[u[1]][j];
          if (conflict(u[0], u[1], na, nb)) {
            continue;
          }
          for (int k = 0; k < (int) g[u[2]].size(); k++) {
            int nc = g[u[2]][k];
            if (conflict(u[0], u[2], na, nc) || conflict(u[1], u[2], nb, nc)) {
              continue;
            }
            if (dist[na][nb][nc] != -1) {
              continue;
            }
            dist[na][nb][nc] = dist[u[0]][u[1]][u[2]] + 1;
            q.push({na, nb, nc});
          }
        }
      }
    }
  }
  return 0;
}
