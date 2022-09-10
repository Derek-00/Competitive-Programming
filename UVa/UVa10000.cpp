/**
 *    author:  willy
 *    created: Sat, 09 Oct 2021 03:48:42 GMT
**/
#include <bits/stdc++.h>

using namespace std;

vector<int> find_topsort(const vector<vector<int>> &g) {
  int n = (int) g.size();
  vector<int> deg(n);
  for (int i = 0; i < n; i++) {
    for (auto &to : g[i]) {
      deg[to]++;
    }
  }
  vector<int> x;
  for (int i = 0; i < n; i++) {
    if (deg[i] == 0) {
      x.push_back(i);
    }
  }
  for (int ptr = 0; ptr < (int) x.size(); ptr++) {
    int i = x[ptr];
    for (auto &to : g[i]) {
      if (--deg[to] == 0) {
        x.push_back(to);
      }
    }
  }
  return x;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  int Case = 0;
  while (cin >> n && n) {
    int s;
    cin >> s;
    --s;
    vector<vector<int>> g(n);
    while (true) {
      int p, q;
      cin >> p >> q;
      if (p == 0 && q == 0) {
        break;
      }
      --p; --q;
      g[p].push_back(q);
    }
    const int inf = (int) 1e9;
    auto tp = find_topsort(g);
    vector<int> dp(n, -inf);
    dp[s] = 0;
    for (int id = 0; id < n; id++) {
      int i = tp[id];
      for (auto &v : g[i]) {
        dp[v] = max(dp[v], dp[i] + 1);
      }
    }
    int mx = -1;
    int pos = -1;
    for (int i = 0; i < n; i++) {
      if (mx < dp[i]) {
        mx = dp[i];
        pos = i + 1;
      }
    }
    cout << "Case " << ++Case << ": The longest path from " << s + 1 << " has length " << mx << ", finishing at " << pos << '.' << "\n\n";
  }
  return 0;
}
