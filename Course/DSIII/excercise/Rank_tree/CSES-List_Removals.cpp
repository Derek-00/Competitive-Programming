/**
 *    author:  willy
 *    created: Sat, 23 Oct 2021 15:29:20 GMT
**/
#include <bits/stdc++.h>

using namespace std;

class segtree {
 public:
  vector<int> tree;
  int n;

  segtree(int _n) : n(_n) {
    tree.resize(n << 2 | 1);
  }

  void build(int v, int l, int r) {
    if (l == r) {
      tree[v] = 1;
      return;
    }
    int y = (l + r) >> 1;
    build(v << 1, l, y);
    build(v << 1 | 1, y + 1, r);
    tree[v] = tree[v << 1] + tree[v << 1 | 1];
  }

  void modify(int v, int l, int r, int id, int val) {
    if (l == r) {
      tree[v] = val;
      return;
    }
    int y = (l + r) >> 1;
    if (id <= y) {
      modify(v << 1, l, y, id, val);
    } else {
      modify(v << 1 | 1, y + 1, r, id, val);
    }
    tree[v] = tree[v << 1] + tree[v << 1 | 1];
  }

  int get(int v, int l, int r, int id) {
    if (l == r) {
      return l;
    }
    int y = (l + r) >> 1;
    if (id <= tree[v << 1]) {
      return get(v << 1, l, y, id);
    } else {
      return get(v << 1 | 1, y + 1, r, id - tree[v << 1]);
    }
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> x(n + 1);
  segtree st(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> x[i];
  }
  st.build(1, 1, n);
  for (int i = 1; i <= n; i++) {
    int p;
    cin >> p;
    int id = st.get(1, 1, n, p);
    st.modify(1, 1, n, id, 0);
    cout << x[id] << " \n"[i == n];
  }
  return 0;
}
