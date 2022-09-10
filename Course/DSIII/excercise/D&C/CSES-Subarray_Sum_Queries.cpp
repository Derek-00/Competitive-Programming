/**
 *    author:  willy
 *    created: Sun, 24 Oct 2021 10:33:41 GMT
**/
#include <bits/stdc++.h>

using namespace std;

class segtree {
 public:
  struct node {
    long long pref;
    long long suf;
    long long sum;
    long long ans;
  };

  vector<node> tree;
  int n;

  segtree(int _n) : n(_n) {
    tree.resize(n << 2);
  }

  node pull(node a, node b) {
    node res;
    res.pref = max(a.pref, a.sum + b.pref);
    res.suf = max(b.suf, a.suf + b.sum);
    res.sum = a.sum + b.sum;
    res.ans = max({a.ans, b.ans, a.suf + b.pref});
    return res;
  }

  void modify(int v, int l, int r, int id, long long val) {
    if (l == r) {
      tree[v] = {val, val, val, val};
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
    int k, x;
    cin >> k >> x;
    st.modify(1, 1, n, k, x);
    cout << max(0LL, st.tree[1].ans) << '\n';
  }
  return 0;
}
