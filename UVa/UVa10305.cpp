#include <bits/stdc++.h>

using namespace std;

class topo {
 public:
  vector<vector<bool>> g;
  vector<int> tp;
  vector<int> c;
  int n, t;

  void init(int _n) {
    n = t = _n;
    g = vector<vector<bool>>(_n, vector<bool>(_n));
    tp = vector<int>(_n);
    c = vector<int>(_n);
  }

  bool dfs(int u){
    c[u] = -1; // is been visited
    for (int v = 0; v < n; v++) {
      if (g[u][v]) {
        if (c[v] < 0) {
          return false; // cyclic
        } else if (!c[v]) {
          dfs(v);
        }
      }
    }
    c[u] = 1; tp[--t] = u;
    return true;
  }

  bool toposort() {
    for (int u = 0; u < n; u++)  {
      if (!c[u]) {
        if (!dfs(u)) {
          return false;
        }
      }
    }
   return true;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  while (cin >> n >> m) {
    if (n == 0 && m == 0) break;
    topo ans;
    ans.init(n);
    while (m--) {
      int x, y;
      cin >> x >> y;
      --x; --y;
      ans.g[x][y] = true;
    }
    if (ans.toposort()) {
      for (int i = 0; i < n; i++) {
        if (i > 0) {
          cout << ' ';
        }
        cout << ans.tp[i] + 1;
      }
      cout << '\n';
    }
  }
  return 0;
}
