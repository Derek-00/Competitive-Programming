/**
 *    author:  willy
 *    created: Sun, 24 Oct 2021 14:15:04 GMT
**/
#include <bits/stdc++.h>

using namespace std;

#define int long long

class segtree {
 public:
  struct node {
    int val = 0;
    int add = 0;

    void apply(int l, int r, int v) {
      val += v * (r - l + 1);
      add += v;
    }
  };

  vector<node> tree;
  int n;

  segtree(int _n) : n(_n) {
    tree.resize(n << 2);
  }

  void push(node& x, node& a, node& b, int l, int r) {
    if (x.add != 0) {
      int y = (l + r) >> 1;
      a.apply(l, y, x.add);
      b.apply(y + 1, r, x.add);
      x.add = 0;
    }
  }

  node pull(node a, node b) {
    node res;
    res.val = a.val + b.val;
    return res;
  }

  void modify(int v, int l, int r, int ll, int rr, int val) {
    if (ll <= l && r <= rr) {
      tree[v].apply(l, r, val);
      return;
    }
    int y = (l + r) >> 1;
    push(tree[v], tree[v << 1], tree[v << 1 | 1], l, r);
    if (ll <= y) {
      modify(v << 1, l, y, ll, rr, val);
    }
    if (rr > y) {
      modify(v << 1 | 1, y + 1, r, ll, rr, val);
    }
    tree[v] = pull(tree[v << 1], tree[v << 1 | 1]);
  }

  int get(int v, int l, int r, int id) {
    if (l == r) {
      return tree[v].val;
    }
    int y = (l + r) >> 1;
    push(tree[v], tree[v << 1], tree[v << 1 | 1], l, r);
    if (id <= y) {
      return get(v << 1, l, y, id);
    } else {
      return get(v << 1 | 1, y + 1, r, id);
    }
  }
};

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  segtree st(n + 1);
  for (int i = 1; i <= n; i++) {
    int v;
    cin >> v;
    st.modify(1, 1, n, i, i, v);
  }
  while (q--) {
    int op;
    cin >> op;
    if (op == 1) {
      int a, b, u;
      cin >> a >> b >> u;
      st.modify(1, 1, n, a, b, u);
    } else {
      int k;
      cin >> k;
      cout << st.get(1, 1, n, k) << '\n';
    }
  }
  return 0;
}
