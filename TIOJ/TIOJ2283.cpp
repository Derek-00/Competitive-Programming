/**
 *    author:  wy
 *    created: Thu, 06 Oct 2022 07:28:44 GMT
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
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<long long> ws(m);
  vector<vector<int>> adj(m);
  vector<vector<int>> gs(n);
  for (int i = 0; i < m; i++) {
    int k;
    cin >> k >> ws[i];
    for (int j = 0; j < k; j++) {
      int x;
      cin >> x;
      --x;
      adj[i].push_back(x);
      gs[x].push_back(i);
    }
  }
  const long long inf = (long long) 9e18;
  min_heap<pair<long long, int>> pq;
  vector<long long> dist(n, inf);
  vector<bool> done(m);
  dist[0] = 0;
  pq.emplace(dist[0], 0);
  while (!pq.empty()) {
    int i = pq.top().second;
    long long expected = pq.top().first;
    pq.pop();
    if (dist[i] != expected) {
      continue;
    }
    for (int g : gs[i]) {
      if (done[g]) {
        continue;
      }
      done[g] = true;
      for (int x : adj[g]) {
        if (dist[i] + ws[g] < dist[x]) {
          dist[x] = dist[i] + ws[g];
          pq.emplace(dist[x], x);
        }
      }
    }
  }
  long long ans = *max_element(dist.begin(), dist.end());
  cout << (ans == inf ? -1 : ans) << '\n';
  return 0;
}
