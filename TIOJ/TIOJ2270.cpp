/**
 *    author:  wy
 *    created: Sun, 02 Oct 2022 11:17:35 GMT
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "C:\Users\wy\C++\solve\_debug\debug.h"
#else
#define debug(...) 42
#endif

bool Valid(vector<vector<int>> g, vector<int> deg) {
  int n = (int) g.size();
  vector<int> x;
  for (int i = 0; i < n; i++) {
    if (deg[i] == 0) {
      x.push_back(i);
    }
  }
  for (int b = 0; b < (int) x.size(); b++) {
    for (int to : g[x[b]]) {
      if (--deg[to] == 0) {
        x.push_back(to);
      }
    }
  }
  return (x.size() == n);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n);
  vector<int> deg(n);
  for (int i = 0; i < m; i++) {
    int a, b;
    char c;
    cin >> a >> c >> b;
    --a; --b;
    if (c == '>') {
      swap(a, b);
    }
    g[a].push_back(b);
    deg[b] += 1;
  }
  if (!Valid(g, deg)) {
    cout << -1 << '\n';
    return 0;
  }
  deque<int> dq;
  for (int i = 0; i < n; i++) {
    if (deg[i] == 0) {
      dq.push_back(i);
    }
  }
  int cnt = 0;
  function<void(int)> Solve = [&](int id) {
    if (cnt > 100) {
      return;
    }
    if (id >= n) {
      cnt += 1;
      return;
    }
    if (dq.empty()) {
      return;
    }
    int sz = (int) dq.size();
    for (int rot = 0; rot < sz && cnt <= 100; rot++) {
      int x = dq.front();
      dq.pop_front();
      int cnt_push = 0;
      for (int to : g[x]) {
        if (--deg[to] == 0) {
          dq.push_back(to);
          cnt_push += 1;
        }
      }
      Solve(id + 1);
      for (int i = 0; i < cnt_push; i++) {
        dq.pop_back();
      }
      for (int to : g[x]) {
        deg[to] += 1;
      }
      dq.push_back(x);
    }
  };
  Solve(0);
  if (cnt <= 100) {
    cout << fixed << setprecision(10) << (double) 100.0 / cnt << '\n';
  } else {
    cout << 0.0 << '\n';
  }
  return 0;
}
