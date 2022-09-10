/**
 *    author:  willy
 *    created: Tue, 26 Oct 2021 02:50:28 GMT
**/
#include <bits/stdc++.h>

using namespace std;

class segtree {
 public:
  struct node {
    int val0 = 0; // val + id
    int val1 = 0; // val - id
  };

  vector<node> tree;
  int n;

  segtree(int _n) : n(_n) {
    tree.resize(2 * n - 1);
  }

  node unite(const node& a, const node& b) {
    node res;
    res.val0 = min(a.val0, b.val0);
    res.val1 = min(a.val1, b.val1);
    return res;
  }

  void pull(int x, int z) {
    tree[x] = unite(tree[x + 1], tree[z]);
  }

  void modify(int x, int l, int r, int id, int val) {
    if (l == r) {
      tree[x] = {val + id, val - id};
      return;
    }
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    if (id <= y) {
      modify(x + 1, l, y, id, val);
    } else {
      modify(z, y + 1, r, id, val);
    }
    pull(x, z);
  }

  node get(int x, int l, int r, int ll, int rr) {
    if (ll <= l && r <= rr) {
      return tree[x];
    }
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  segtree st(n + 1);
  for (int i = 1; i <= n; i++) {
    int v;
    cin >> v;
    st.modify(1, 1, n, i, v);
  }
  while (q--) {
    int op;
    cin >> op;
    if (op == 1) {
      int k, x;
      cin >> k >> x;
      st.modify(1, 1, n, k, x);
    } else {
      int k;
      cin >> k;
      auto L = st.get(1, 1, n, 1, k);
      auto R = st.get(1, 1, n, k, n);
      cout << min(L.val1 + k, R.val0 - k) << '\n';
    }
  }
  return 0;
}
