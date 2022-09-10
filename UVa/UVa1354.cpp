/**
 *    author:  willy
 *    created: Wed, 25 Aug 2021 13:41:37 GMT
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed << setprecision(10);
  int tt;
  cin >> tt;
  while (tt--) {
    double r;
    cin >> r;
    int s;
    cin >> s;
    vector<double> w(s);
    for (int i = 0; i < s; i++) {
      cin >> w[i];
    }
    const int ALL = 1 << s;
    vector<double> sum(ALL, 0);
    for (int i = 0; i < ALL; i++) {
      for (int j = 0; j < s; j++) {
        if (i & (1 << j)) {
          sum[i] += w[j];
        }
      }
    }
    vector<bool> vis(ALL);
    vector<vector<pair<double, double>>> tree(ALL);
    function<void(int)> dfs = [&](int subset) {
      if (vis[subset]) {
        return;
      }
      vis[subset] = true;
      bool has = false;
      int L = (subset - 1) & subset;
      while (L) {
        has |= true;
        int R = subset ^ L;
        double da = sum[R] / sum[subset];
        double db = sum[L] / sum[subset];
        dfs(L);
        dfs(R);
        for (int i = 0; i < (int) tree[L].size(); i++) {
          for (int j = 0; j < (int) tree[R].size(); j++) {
            double nL = max(tree[L][i].first + da, tree[R][j].first - db);
            double nR = max(tree[R][j].second + db, tree[L][i].second - da);
            if (nL + nR < r) {
              tree[subset].emplace_back(nL, nR);
            }
          }
        }
        L = (L - 1) & subset;
      }
      if (!has) {
        tree[subset].emplace_back(0.0, 0.0);
      }
    };
    int root = ALL - 1;
    dfs(root);
    double ans = -1;
    for (int i = 0; i < (int) tree[root].size(); i++) {
      ans = max(ans, tree[root][i].first + tree[root][i].second);
    }
    if (ans == -1) {
      cout << -1 << '\n';
    } else {
      cout << ans << '\n';
    }
  }
  return 0;
}
