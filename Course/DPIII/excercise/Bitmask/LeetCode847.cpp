/**
 *    author:  willy
 *    created: Fri, 15 Oct 2021 14:26:48 GMT
**/
#include <bits/stdc++.h>

using namespace std;

int shortestPathLength(vector<vector<int>>& graph) {
  const int n = (int) graph.size();
  const int inf = (int) 1e9;
  vector<vector<int>> dist(n, vector<int>(n, inf));
  for (int i = 0; i < n; i++) {
    for (auto& to : graph[i]) {
      dist[i][to] = dist[to][i] = 1;
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < n; k++) {
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }
  const int BASE = (1 << n);
  vector<vector<int>> dp(n, vector<int>(BASE, inf));
  for (int i = 0; i < n; i++) {
    dp[i][1 << i] = 0;
  }
  for (int bs = 1; bs < BASE; bs++) {
    for (int i = 0; i < n; i++) {
      if (!(bs & (1 << i))) continue;
      for (int v = 0; v < n; v++) {
        if (!(bs & (1 << v)) || i == v) continue;
        dp[i][bs] = min(dp[i][bs], dp[v][bs ^ (1 << i)] + dist[i][v]);
      }
    }
  }
  int ans = inf;
  for (int i = 0; i < n; i++) {
    ans = min(ans, dp[i][BASE - 1]);
  }
  return ans;
}
