/**
 *    author:  willy
 *    created: Mon, 25 Oct 2021 01:29:36 GMT
**/
#include <bits/stdc++.h>

using namespace std;

#define int long long

class segtree {
 public:
  struct node {
    int sum = 0;
    int add = 0;

    void apply(int l, int r, int v) {
      sum = v * (r - l + 1);
      add = v;
    }
  };

  vector<node> tree;
  int n;

  segtree(int _n) : n(_n) {
    tree.resize(n << 2);
  }

  node unite(const node& a, const node& b) {
    node res;
    res.sum = a.sum + b.sum;
    return res;
  }

  void push(int x, int l, int r) {
    if (tree[x].add != 0) {
      int y = (l + r) >> 1;
      tree[x << 1].apply(l, y, tree[x].add);
      tree[x << 1 | 1].apply(y + 1, r, tree[x].add);
      tree[x].add = 0;
    }
  }

  void pull(int x) {
    tree[x] = unite(tree[x << 1], tree[x << 1 | 1]);
  }

  void modify(int x, int l, int r, int ll, int rr, int v) {
    if (ll <= l && r <= rr) {
      tree[x].apply(l, r, v);
      return;
    }
    push(x, l, r);
    int y = (l + r) >> 1;
    if (ll <= y) {
      modify(x << 1, l, y, ll, rr, v);
    }
    if (rr > y) {
      modify(x << 1 | 1, y + 1, r, ll, rr, v);
    }
    pull(x);
  }

  node get(int x, int l, int r, int ll, int rr) {
    if (ll <= l && r <= rr) {
      return tree[x];
    }
    push(x, l, r);
    int y = (l + r) >> 1;
    node res{};
    if (rr <= y) {
      res = get(x << 1, l, y, ll, rr);
    } else {
      if (ll > y) {
        res = get(x << 1 | 1, y + 1, r, ll, rr);
      } else {
        res = unite(get(x << 1, l, y, ll, rr), get(x << 1 | 1, y + 1, r, ll, rr));
      }
    }
    pull(x);
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
      cout << st.get(1, 1, n, l + 1, r).sum << '\n';
    }
  }
  return 0;
}
