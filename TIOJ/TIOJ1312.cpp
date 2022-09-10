/**
 *    author:  willy
 *    created: Wed, 09 Feb 2022 03:19:51 GMT
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "C:\Users\wy\C++\solve\_debug\debug.h"
#else
#define debug(...) 42
#endif

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
      if (x < y) {
        swap(x, y);
      }
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
  while (cin >> n >> m) {
    dsu d(n);
    for (int i = 0; i < m; i++) {
      int a, b;
      cin >> a >> b;
      --a; --b;
      d.unite(a, b);
    }
    int k;
    cin >> k;
    cout << d.get(k - 1) + 1 << '\n';
  }
  return 0;
}
