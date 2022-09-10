/**
 *    author:  willy
 *    created: Tue, 09 Nov 2021 06:02:11 GMT
**/
#include <iostream>
#include <vector>

using namespace std;

const int inf = (int) 1e9;

int bfs(int x, int y, int z) {
  vector<vector<bool>> vis(x + 1, vector<bool>(y + 1, false));
  vector<vector<int>> dist(x + 1, vector<int>(y + 1, inf));
  vector<pair<int, int>> que(1, make_pair(0, 0));
  vis[0][0] = true;
  dist[0][0] = 0;
  for (int bfs = 0; bfs < (int) que.size(); bfs++) {
    int a = que[bfs].first;
    int b = que[bfs].second;
    if (a == z || b == z) {
      return dist[a][b];
    }
    if (a != x && !vis[x][b]) {
      vis[x][b] = true;
      dist[x][b] = dist[a][b] + 1;
      que.push_back(make_pair(x, b));
    }
    if (a != 0) {
      int trap = min(a, y - b);
      int new_a = a - trap;
      int new_b = b + trap;
      if (!vis[new_a][new_b]) {
        vis[new_a][new_b] = true;
        dist[new_a][new_b] = dist[a][b] + 1;
        que.push_back(make_pair(new_a, new_b));
      }
    }
    if (b != 0 && !vis[a][0]) {
      vis[a][0] = true;
      dist[a][0] = dist[a][b] + 1;
      que.push_back(make_pair(a, 0));
    }
  }
  return inf;
}

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int x, y, z;
    cin >> x >> y >> z;
    int ans = min(bfs(x, y, z), bfs(y, x, z));
    cout << (ans == inf ? -1 : ans) << endl;
  }
  return 0;
}
