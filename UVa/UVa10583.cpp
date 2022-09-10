/**
 *    author:  willy
 *    created: Wed, 11 Aug 2021 16:37:52 GMT
**/
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
  int kase = 0;
  while (cin >> n >> m) {
    if (n == 0 && m == 0) {
      break;
    }
    dsu d(n);
    int ans = n;
    for (int i = 0; i < m; i++) {
      int a, b;
      cin >> a >> b;
      --a; --b;
      if (d.unite(a, b)) {
        --ans;
      }
    }
    cout << "Case " << ++kase << ": " << ans << '\n';
  }
  return 0;
}
