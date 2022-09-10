/**
 *    author:  willy
 *    created: Mon, 06 Dec 2021 03:01:22 GMT
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> deg(n, 0);
  vector<vector<int>> g(n);
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    --x; --y;
    g[x].push_back(y);
    deg[y]++;
  }
  vector<int> x;
  for (int i = 0; i < n; i++) {
    if (deg[i] == 0) {
      x.push_back(i);
    }
  }
  for (int ptr = 0; ptr < (int) x.size(); ptr++) {
    int i = x[ptr];
    for (auto& to : g[i]) {
      if (--deg[to] == 0) {
        x.push_back(to);
      }
    }
  }
  vector<int> dp(n);
  for (int ptr = 0; ptr < n; ptr++) {
    int i = x[ptr];
    for (auto& to : g[i]) {
      dp[to] = max(dp[to], dp[i] + 1);
    }
  }
  cout << *max_element(dp.begin(), dp.end()) << '\n';
  return 0;
}
