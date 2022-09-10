/**
 *    author:  willy
 *    created: Thu, 07 Oct 2021 15:34:21 GMT
**/
#include <bits/stdc++.h>

using namespace std;

// problem URL: https://zerojudge.tw/ShowProblem?problemid=a454

vector<int> find_topsort(const vector<vector<int>> &g) {
  int n = (int) g.size();
  vector<int> deg(n, 0);
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
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    vector<int> w(n);
    for (int i = 0; i < n; i++) {
      cin >> w[i];
      int k;
      cin >> k;
      for (int j = 0; j < k; j++) {
        int v;
        cin >> v;
        --v;
        g[i].push_back(v);
      }
    }
    auto tp = find_topsort(g);
    vector<int> dp(w.begin(), w.end());
    for (int i = 0; i < n; i++) {
      int v = tp[i];
      for (auto &to : g[v]) {
        dp[to] = max(dp[to], dp[v] + w[to]);
      }
    }
    cout << *max_element(dp.begin(), dp.end()) << '\n';
  }
  return 0;
}
