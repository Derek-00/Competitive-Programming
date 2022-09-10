/**
 *    author:  willy
 *    created: Sat, 23 Oct 2021 15:49:23 GMT
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
  int n, m;
  cin >> n >> m;
  vector<int> a(n + 1);
  segtree st(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    st.modify(1, 1, n, i, a[i]);
  }
  for (int i = 0; i < m; i++) {
    int t, k;
    cin >> t >> k;
    k++;
    if (t == 1) {
      a[k] ^= true;
      st.modify(1, 1, n, k, a[k]);
    } else {
      cout << st.get(1, 1, n, k) - 1 << '\n';
    }
  }
  return 0;
}
