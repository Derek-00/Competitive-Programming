/**
 *    author:  wy
 *    created: Thu, 03 Nov 2022 15:48:06 GMT
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "C:\Users\wy\C++\solve\_debug\debug.h"
#else
#define debug(...) 42
#endif

template<typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    for (int i = 0; i < m; i++) {
      int u, v;
      cin >> u >> v;
      g[u].push_back(v);
      g[v].push_back(u);
    }
    int mx = 0;
    for (int i = 0; i < n; i++) {
      sort(g[i].begin(), g[i].end());
      int smlr = (int) (g[i].end() - upper_bound(g[i].begin(), g[i].end(), i));
      mx = max(mx, smlr);
    }
    cout << mx << " ";

    vector<int> deg(n);
    min_heap<pair<int, int>> pq;
    for (int i = 0; i < n; i++) {
      deg[i] = (int) g[i].size();
      pq.emplace(deg[i], i);
    }
    vector<bool> chosen(n);
    vector<int> res(n);
    while (!pq.empty()) {
      int u = pq.top().second;
      int d = pq.top().first;
      pq.pop();
      if (chosen[u]) {
        continue;
      }
      chosen[u] = true;
      res[u] = d;
      for (int v : g[u]) {
        if (!chosen[v]) {
          --deg[v];
          pq.emplace(deg[v], v);
        }
      }
    }
    cout << *max_element(res.begin(), res.end()) << '\n';
  }
  return 0;
}
