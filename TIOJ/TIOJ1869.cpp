/**
 *    author:  willy
 *    created: Fri, 20 Aug 2021 13:30:16 GMT
**/
#include <bits/stdc++.h>

using namespace std;

template <typename T>
class fenwick2d {
 public:
  vector< vector<T> > fenw;
  int n, m;

  fenwick2d(int _n, int _m) : n(_n), m(_m) {
    fenw.resize(n);
    for (int i = 0; i < n; i++) {
      fenw[i].resize(m);
    }
  }

  inline void modify(int i, int j, T v) {
    int x = i;
    while (x < n) {
      int y = j;
      while (y < m) {
        fenw[x][y] += v;
        y |= (y + 1);
      }
      x |= (x + 1);
    }
  }

  inline T get(int i, int j) {
    T v{};
    int x = i;
    while (x >= 0) {
      int y = j;
      while (y >= 0) {
        v += fenw[x][y];
        y = (y & (y + 1)) - 1;
      }
      x = (x & (x + 1)) - 1;
    }
    return v;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  fenwick2d<int> fenw(n + 1, n + 1);
  int op;
  while (cin >> op) {
    if (op == 1) {
      int x, y, z;
      cin >> x >> y >> z;
      ++x; ++y;
      fenw.modify(x, y, z);
    }
    if (op == 2) {
      int xa, ya, xb, yb;
      cin >> xa >> ya >> xb >> yb;
      ++xa; ++ya; ++xb; ++yb;
      cout << fenw.get(xb, yb) - fenw.get(xb, ya - 1) - fenw.get(xa - 1, yb) + fenw.get(xa - 1, ya - 1) << '\n';
    }
  }
  return 0;
}
