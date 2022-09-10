/**
 *    author:  willy
 *    created: Tue, 09 Nov 2021 06:49:47 GMT
**/
#include <iostream>
#include <vector>

using namespace std;

const int N = 10;
const int inf = (int) 1e9;

const int dx[] = {-1, -2, -2, -1, 1, 2, 2, 1};
const int dy[] = {-2, -1, 1, 2, 2, 1, -1, -2};

vector< vector<int> > dist(3);
vector< vector<int> > ans(3);
int n;

int Comp(vector<int> a, vector<int> b) {
  const int sz = (int) a.size();
  for (int i = 0; i < sz; i++) {
    if (a[i] < b[i]) {
      return -1;
    }
    if (a[i] > b[i]) {
      return 1;
    }
  }
  return 0;
}

void dfs(int x, int y, int cnt) {
  if (cnt == n * 3) {
    for (int i = 0; i < 3; i++) {
      int s = Comp(dist[i], ans[i]);
      if (s == 0) continue;
      if (s < 0) {
        ans = dist;
      }
      break;
    }
    return;
  }
  for (int dir = 0; dir < 8; dir++) {
    int nx = x + dx[dir];
    int ny = y + dy[dir];
    if (nx >= 0 && nx < 3 && ny >= 0 && ny < n) {
      if (cnt < dist[nx][ny]) {
        dist[nx][ny] = ++cnt;
        dfs(nx, ny, cnt--);
        dist[nx][ny] = inf;
      }
    }
  }
}

int main() {
  cin >> n;
  for (int i = 0; i < 3; i++) {
    dist[i].resize(n, inf);
    ans[i].resize(n, inf);
  }
  dist[0][0] = ans[0][0] = 1;
  dfs(0, 0, dist[0][0]);
  bool ok = true;
  if (ans[0][1] == inf) {
    cout << 0 << endl;
    return 0;
  }
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < n; j++) {
      cout << ans[i][j] << " ";
    }
  }
  cout << endl;
  return 0;
}
