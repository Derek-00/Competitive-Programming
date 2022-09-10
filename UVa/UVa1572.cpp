#include <bits/stdc++.h>

using namespace std;

inline int encode(char a, char b) {
  return (a - 'A') * 2 + (b == '-');
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  while (cin >> n) {
    const int cc = 26 * 2;
    vector<vector<bool>> g(cc, vector<bool>(cc));
    while (n--) {
      string s;
      cin >> s;
      for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
          if (i == j || s[i * 2] == '0' || s[j * 2] == '0') {
            continue;
          }
          int a = encode(s[i * 2], s[i * 2 + 1]) ^ 1;
          int b = encode(s[j * 2], s[j * 2 + 1]);
          g[a][b] = true;
        }
      }
    }
    vector<int> c(cc);
    function<bool(int)> dfs = [&](int u) {
      c[u] = -1;
      for (int v = 0; v < cc; v++) {
        if (g[u][v]) {
          if (c[v] == -1) {
            return true;
          }
          if (c[v] == 0 && dfs(v)) {
            return true;
          }
        }
      }
      c[u] = 1;
      return false;
    };
    bool is_cycle = false;
    for (int i = 0; i < cc; i++) {
      if (c[i] == 0 && dfs(i)) {
        is_cycle = true;
        break;
      }
    }
    cout << (is_cycle ? "unbounded" : "bounded") << '\n';
  }
  return 0;
}
