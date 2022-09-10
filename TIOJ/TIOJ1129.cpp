/**
 *    author:  willy
 *    created: Sun, 15 Aug 2021 07:53:13 GMT
**/
#include <bits/stdc++.h>

using namespace std;

class dsu {
 public:
  vector<int> sz;
  vector<int> p;
  int n;

  dsu(int _n) : n(_n) {
    sz.resize(n, 1);
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
      if (sz[x] > sz[y]) {
        swap(x, y);
      }
      p[x] = y;
      sz[y] += sz[x];
      sz[x] = 0;
      return true;
    }
    return false;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int a, b, c;
  while (cin >> a >> b >> c) {
    vector<pair<int, int>> coor(b + 1);
    coor[0] = make_pair(a, a);
    for (int i = 1; i <= b; i++) {
      int x = (coor[i - 1].first * 269 + 11) % 103;
      int y = (coor[i - 1].second * 271 + 13) % 97;
      coor[i] = make_pair(x, y);
    }
    dsu d(b + 1);
    sort(coor.begin() + 1, coor.end());
    for (int i = 1; i <= b; i++) {
      for (int j = i + 1; j <= b; j++) {
        if (coor[j].first - coor[i].first > c) {
          break;
        }
        int dist = (coor[i].first - coor[j].first) * (coor[i].first - coor[j].first) + (coor[i].second - coor[j].second) * (coor[i].second - coor[j].second);
        if (dist <= c * c) {
          d.unite(i, j);
        }
      }
    }
    vector<int> ans;
    for (int i = 1; i <= b; i++) {
      if (d.sz[i] != 0) {
        ans.push_back(d.sz[i]);
      }
    }
    sort(ans.begin(), ans.end());
    cout << (int) ans.size() << '\n';
    for (int i = 0; i < (int) ans.size(); i++) {
      if (i > 0) {
        cout << " ";
      }
      cout << ans[i];
    }
    cout << '\n';
  }
  return 0;
}
