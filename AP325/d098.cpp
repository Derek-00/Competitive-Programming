#include <bits/stdc++.h>

using namespace std;

class dsu {
 public:
  vector<int> p;
  int n;

  dsu(int _n) : n(_n) {
    p.resize(n);
    iota(p.begin(), p.end(), 0);
  }

  inline int get(int x) {
    return (x == p[x] ? x : (p[x] = get(p[x])));
  }

  inline bool unite(int x, int y) {
    x = get(x);
    y = get(y);
    if (x != y) {
      p[x] = y;
      return true;
    }
    return false;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> weight(m);
  vector<pair<int, int>> edges(m);
  for (int i = 0; i < m; i++) {
    cin >> edges[i].first >> edges[i].second >> weight[i];
  }
  vector<int> idx(m);
  iota(idx.begin(), idx.end(), 0);
  sort(idx.begin(), idx.end(), [&](int i, int j) {
    return weight[i] < weight[j];
  });
  dsu d(n);
  int cnt = 0;
  long long ans = 0;
  for (auto i : idx) {
    if (d.unite(edges[i].first, edges[i].second)) {
      ++cnt;
      ans += weight[i];
    }
  }
  cout << (cnt == n - 1 ? ans : -1) << '\n';
  return 0;
}
