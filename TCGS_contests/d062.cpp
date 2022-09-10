/**
 *    author:  willy
 *    created: Thu, 11 Nov 2021 13:33:27 GMT
**/
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

const int n = 16;
const int inf = (int) 1e9;

int main() {
  int g[16][4] = {{1, 4, -1, -1}, {0, 2, 5, -1}, {1, 3, 6, -1}, {2, 7, -1, -1}, {0, 5, 8, -1}, {1, 4, 9, -1}, {2, 7, 10, -1}, {3, 6, 11, -1}, {4, 9, 12, -1}, {5, 8, 10, 13}, {6, 9, 11, -1}, {7, 10, 15, -1}, {8, 13, -1, -1}, {9, 12, 14, -1}, {13, 15, -1, -1}, {11, 14, -1, -1}};
  vector< vector<int> > dist(n, vector<int>(n, inf));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 4; j++) {
      if (g[i][j] == -1) continue;
      dist[i][g[i][j]] = 1;
    }
  }
  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }
  vector< vector<int> > dp(n, vector<int>(1 << n, inf));
  for (int i = 0; i < n; i++) {
    dp[i][1 << i] = 0;
  }
  for (int bs = 1; bs < (1 << n); bs++) {
    for (int i = 0; i < n; i++) {
      if (!(bs & (1 << i))) continue;
      for (int j = 0; j < n; j++) {
        if (!(bs & (1 << j))) continue;
        dp[i][bs] = min(dp[i][bs], dp[j][bs ^ (1 << i)] + dist[j][i]);
      }
    }
  }
  int tt;
  cin >> tt;
  string foo = "";
  getline(cin, foo);
  while (tt--) {
    string s;
    getline(cin, s);
    stringstream ss(s);
    char node;
    vector<char> path;
    while (ss >> node) {
      path.push_back(node);
    }
    int all = 0;
    for (int i = 0; i < (int) path.size(); i++) {
      int id = (int) (path[i] - 'a');
      all |= (1 << id);
    }
    int start = (int) (path[0] - 'a');
    cout << dp[start][all] << endl;
  }
  return 0;
}
