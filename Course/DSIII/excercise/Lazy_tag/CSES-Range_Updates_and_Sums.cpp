/**
 *    author:  willy
 *    created: Mon, 25 Oct 2021 01:56:19 GMT
**/
#include <bits/stdc++.h>

using namespace std;

#define int long long

class segtree {
 public:
  struct node {
    int sum = 0;
    int add = 0;
    int chg = 0;

    void apply_add(int l, int r, int v) {
      sum += v * (r - l + 1);
      add += v;
    }

    void apply_chg(int l, int r, int v) {
      sum = v * (r - l + 1);
      chg = v;
      add = 0;
    }
  };

  vector<node> tree;
  int n;

  segtree(int _n) : n(_n) {
    tree.resize(2 * n - 1);
  }

  node unite(const node& a, const node& b) {
    node res;
    res.sum = a.sum + b.sum;
    return res;
  }

  void push(int x, int l, int r) {
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    if (tree[x].chg != 0) {
      tree[x + 1].apply_chg(l, y, tree[x].chg);
      tree[z].apply_chg(y + 1, r, tree[x].chg);
      tree[x].chg = 0;
    }
    if (tree[x].add != 0) {
      tree[x + 1].apply_add(l, y, tree[x].add);
      tree[z].apply_add(y + 1, r, tree[x].add);
      tree[x].add = 0;
    }
  }

  void pull(int x, int z) {
    tree[x] = unite(tree[x + 1], tree[z]);
  }

  void modify_add(int x, int l, int r, int ll, int rr, int v) {
    if (ll <= l && r <= rr) {
      tree[x].apply_add(l, r, v);
      return;
    }
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    push(x, l, r);
    if (ll <= y) {
      modify_add(x + 1, l, y, ll, rr, v);
    }
    if (rr > y) {
      modify_add(z, y + 1, r, ll, rr, v);
    }
    pull(x, z);
  }

  void modify_chg(int x, int l, int r, int ll, int rr, int v) {
    if (ll <= l && r <= rr) {
      tree[x].apply_chg(l, r, v);
      return;
    }
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    push(x, l, r);
    if (ll <= y) {
      modify_chg(x + 1, l, y, ll, rr, v);
    }
    if (rr > y) {
      modify_chg(z, y + 1, r, ll, rr, v);
    }
    pull(x, z);
  }

  node get(int x, int l, int r, int ll, int rr) {
    if (ll <= l && r <= rr) {
      return tree[x];
    }
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    push(x, l, r);
    node res{};
    if (rr <= y) {
      res = get(x + 1, l, y, ll, rr);
    } else {
      if (ll > y) {
        res = get(z, y + 1, r, ll, rr);
      } else {
        res = unite(get(x + 1, l, y, ll, rr), get(z, y + 1, r, ll, rr));
      }
    }
    pull(x, z);
    return res;
  }
};

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  segtree st(n);
  for (int i = 0; i < n; i++) {
    int v;
    cin >> v;
    st.modify_chg(0, 0, n - 1, i, i, v);
  }
  while (q--) {
    int op;
    cin >> op;
    if (op == 1) {
      int a, b, x;
      cin >> a >> b >> x;
      --a; --b;
      st.modify_add(0, 0, n - 1, a, b, x);
    }
    if (op == 2) {
      int a, b, x;
      cin >> a >> b >> x;
      --a; --b;
      st.modify_chg(0, 0, n - 1, a, b, x);
    }
    if (op == 3) {
      int a, b;
      cin >> a >> b;
      --a; --b;
      cout << st.get(0, 0, n - 1, a, b).sum << '\n';
    }
  }
  return 0;
}
