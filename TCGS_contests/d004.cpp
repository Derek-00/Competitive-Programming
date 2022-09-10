/**
 *    author:  willy
 *    created: Thu, 11 Nov 2021 02:09:28 GMT
**/
#include <iostream>

using namespace std;

const int n = 5;
const int dx[] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};

int g[n][n];

int Count(int x, int y) {
  int cnt = 0;
  for (int dir = 0; dir < 8; dir++) {
    int nx = x + dx[dir];
    int ny = y + dy[dir];
    if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
      if (g[nx][ny] == 1) {
        cnt++;
      }
    }
  }
  return cnt;
}

void Do() {
  int ng[n][n];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int has = Count(i, j);
      if (g[i][j] == 1) {
        if (has <= 1) {
          ng[i][j] = 0;
        } else {
          if (has <= 3) {
            ng[i][j] = 1;
          } else {
            ng[i][j] = 0;
          }
        }
      } else {
        if (has == 3) {
          ng[i][j] = 1;
        } else {
          ng[i][j] = 0;
        }
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      g[i][j] = ng[i][j];
    }
  }
}

int main() {
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < n; j++) {
      if (s[j * 2] == '1') {
        g[i][j] = 1;
      } else {
        g[i][j] = 0;
      }
    }
  }
  for (int Case = 2; Case <= 5; Case++) {
    Do();
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cnt += g[i][j];
      }
    }
    cout << "第" << Case << "代: " << cnt << "個細胞存活" << '\n';
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (j > 0) {
          cout << ',';
        }
        cout << g[i][j];
      }
      cout << '\n';
    }
  }
  return 0;
}
