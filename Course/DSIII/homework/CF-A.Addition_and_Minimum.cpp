/**
 *    author:  willy
 *    created: Sun, 24 Oct 2021 14:49:13 GMT
**/
#include <bits/stdc++.h>

using namespace std;

#define int long long

const int inf = (int) 1e18;

class segtree {
 public:
  struct node {
    int mn = 0;
    int add = 0;

    void apply(int v) {
      mn += v;
      add += v;
    }
  };

  vector<node> tree;
  int n;

  segtree(int _n) : n(_n) {
    tree.resize(n << 2);
  }

  node pull(node a, node b) {
    node res;
    res.mn = min(a.mn, b.mn);
    return res;
  }

  void push(node& x, node& a, node& b) {
    if (x.add != 0) {
      a.apply(x.add);
      b.apply(x.add);
      x.add = 0;
    }
  }

  void modify(int v, int l, int r, int ll, int rr, int val) {
    if (ll <= l && r <= rr) {
      tree[v].apply(val);
      return;
    }
    int lc = v << 1;
    int rc = v << 1 | 1;
    int y = (l + r) >> 1;
    push(tree[v], tree[lc], tree[rc]);
    if (ll <= y) {
      modify(lc, l, y, ll, rr, val);
    }
    if (rr > y) {
      modify(rc, y + 1, r, ll, rr, val);
    }
    tree[v] = pull(tree[lc], tree[rc]);
  }

  node get(int v, int l, int r, int ll, int rr) {
    if (ll <= l && r <= rr) {
      return tree[v];
    }
    int lc = v << 1;
    int rc = v << 1 | 1;
    int y = (l + r) >> 1;
    push(tree[v], tree[lc], tree[rc]);
    node res;
    res.mn = inf;
    if (ll <= y) {
      res = pull(res, get(lc, l, y, ll, rr));
    }
    if (rr > y) {
      res = pull(res, get(rc, y + 1, r, ll, rr));
    }
    return res;
  }
};

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  segtree st(n + 1);
  while (m--) {
    int op;
    cin >> op;
    if (op == 1) {
      int l, r, v;
      cin >> l >> r >> v;
      st.modify(1, 1, n, l + 1, r, v);
    } else {
      int l, r;
      cin >> l >> r;
      cout << st.get(1, 1, n, l + 1, r).mn << '\n';
    }
  }
  return 0;
}
