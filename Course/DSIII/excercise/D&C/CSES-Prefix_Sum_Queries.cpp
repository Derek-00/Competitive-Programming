/**
 *    author:  willy
 *    created: Sun, 24 Oct 2021 10:49:16 GMT
**/
#include <bits/stdc++.h>

using namespace std;

class segtree {
 public:
  struct node {
    long long pref = 0;
    long long sum = 0;
  };

  vector<node> tree;
  int n;

  segtree(int _n) : n(_n) {
    tree.resize(n << 2);
  }

  node pull(node a, node b) {
    node res;
    res.pref = max(a.pref, a.sum + b.pref);
    res.sum = a.sum + b.sum;
    return res;
  }

  void modify(int v, int l, int r, int id, long long val) {
    if (l == r) {
      tree[v] = {val, val};
      return;
    }
    int y = (l + r) >> 1;
    if (id <= y) {
      modify(v << 1, l, y, id, val);
    } else {
      modify(v << 1 | 1, y + 1, r, id, val);
    }
    tree[v] = pull(tree[v << 1], tree[v << 1 | 1]);
  }

  node get(int v, int l, int r, int ll, int rr) {
    if (ll <= l && r <= rr) {
      return tree[v];
    }
    int y = (l + r) >> 1;
    node res;
    if (ll <= y) {
      res = pull(res, get(v << 1, l, y, ll, rr));
    }
    if (y < rr) {
      res = pull(res, get(v << 1 | 1, y + 1, r, ll, rr));
    }
    return res;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  vector<int> a(n + 1);
  segtree st(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    st.modify(1, 1, n, i, (long long) a[i]);
  }
  while (q--) {
    int op;
    cin >> op;
    if (op == 1) {
      int k, u;
      cin >> k >> u;
      st.modify(1, 1, n, k, u);
    } else {
      int a, b;
      cin >> a >> b;
      cout << max(0LL, st.get(1, 1, n, a, b).pref) << '\n';
    }
  }
  return 0;
}
