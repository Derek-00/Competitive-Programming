/**
 *    author:  willy
 *    created: Fri, 22 Oct 2021 13:56:13 GMT
**/
#include <bits/stdc++.h>

using namespace std;

#define int long long

class segtree {
 public:
  vector<int> tree;
  int n;

  segtree(int _n) : n(_n) {
    tree.resize(n << 2);
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

  int get(int v, int l, int r, int ll, int rr) {
    if (ll <= l && r <= rr) {
      return tree[v];
    }
    int res = 0;
    int y = (l + r) >> 1;
    if (ll <= y) {
      res += get(v << 1, l, y, ll, rr);
    }
    if (y < rr) {
      res += get(v << 1 | 1, y + 1, r, ll, rr);
    }
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
    st.modify(1, 0, n - 1, i, v);
  }
  while (q--) {
    int k, a, b;
    cin >> k >> a >> b;
    if (k == 1) {
      st.modify(1, 0, n - 1, a - 1, b);
    } else {
      --a; --b;
      cout << st.get(1, 0, n - 1, a, b) << '\n';
    }
  }
  return 0;
}
