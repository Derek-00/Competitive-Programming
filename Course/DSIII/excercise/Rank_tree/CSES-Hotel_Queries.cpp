/**
 *    author:  willy
 *    created: Sat, 23 Oct 2021 12:35:39 GMT
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
    tree[v] = max(tree[v << 1], tree[v << 1 | 1]);
  }

  int get(int v, int l, int r, int val) {
    if (l == r) {
      return l;
    }
    // binary search
    // also the rank tree
    int y = (l + r) >> 1;
    if (tree[v << 1] >= val) {
      return get(v << 1, l, y, val);
    } else {
      return get(v << 1 | 1, y + 1, r, val);
    }
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> h(n + 1);
  segtree st(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> h[i];
    st.modify(1, 1, n, i, h[i]);
  }
  for (int i = 0; i < m; i++) {
    int r;
    cin >> r;
    if (r > st.tree[1]) {
      cout << 0 << " \n"[i == m - 1];
    } else {
      int id = st.get(1, 1, n, r);
      cout << id << " \n"[i == m - 1];
      h[id] -= r;
      st.modify(1, 1, n, id, h[id]);
    }
  }
  return 0;
}
