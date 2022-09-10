/**
 *    author:  willy
 *    created: Tue, 28 Dec 2021 15:23:07 GMT
**/
#include <bits/stdc++.h>

using namespace std;

long long Solve(const vector<vector<pair<int, int>>>& g, int x) {
  int n = (int) g.size();
  vector<bool> vis(n);
  long long res = 0;
  for (int i = 0; i < n; i++) {
    if (vis[i]) {
      continue;
    }
    vis[i] = true;
    vector<int> que(1, i);
    int cnt = 1;
    for (int b = 0; b < (int) que.size(); b++) {
      for (auto& p : g[que[b]]) {
        if (vis[p.first] || p.second > x) {
          continue;
        }
        vis[p.first] = true;
        cnt += 1;
        que.push_back(p.first);
      }
    }
    res += (long long) cnt * (cnt + 1) / 2;
  }
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m, x;
  cin >> n >> m >> x;
  vector<vector<pair<int, int>>> g(n);
  for (int i = 0; i < m; i++) {
    int a, b, w;
    cin >> a >> b >> w;
    --a; --b;
    g[a].emplace_back(b, w);
    g[b].emplace_back(a, w);
  }
  cout << Solve(g, x) - Solve(g, x - 1) << '\n';
  return 0;
}
