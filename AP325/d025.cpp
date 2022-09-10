/**
 *    author:  wy
 *    created: Wed, 06 Jul 2022 07:57:14 GMT
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "C:\Users\wy\C++\solve\_debug\debug.h"
#else
#define debug(...) 42
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> p(n, -1);
  vector<int> deg(n);
  vector<int> que;
  for (int i = 0; i < n; i++) {
    cin >> deg[i];
    if (deg[i] == 0) {
      que.push_back(i);
    }
    for (int j = 0; j < deg[i]; j++) {
      int ch;
      cin >> ch;
      p[ch - 1] = i;
    }
  }
  int ans = 0;
  int root = -1;
  vector<int> h(n);
  for (int b = 0; b < (int) que.size(); b++) {
    int u = que[b];
    int v = p[u];
    ans += h[u];
    if (v == -1) {
      root = u;
      continue;
    }
    h[v] = max(h[v], h[u] + 1);
    if (--deg[v] == 0) {
      que.push_back(v);
    }
  }
  cout << root + 1 << '\n';
  cout << ans << '\n';
  return 0;
}
