/**
 *    author:  willy
 *    created: Wed, 25 Aug 2021 16:49:18 GMT
**/
#include <bits/stdc++.h>

using namespace std;

const int inf = (int) 1e9;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  while (cin >> n && n) {
    vector<vector<int>> dist(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cin >> dist[i][j];
        if (dist[i][j] == 0) {
          dist[i][j] = inf;
        }
      }
    }
    for (int k = 0; k < n; k++) {
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
        }
      }
    }
    int ans = inf;
    for (int i = 0; i < n; i++) {
      ans = min(ans, dist[i][i]);
    }
    cout << (ans == inf ? -1 : ans) << '\n';
  }
  return 0;
}
