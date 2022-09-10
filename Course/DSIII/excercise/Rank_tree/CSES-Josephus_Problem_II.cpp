/**
 *    author:  willy
 *    created: Sun, 24 Oct 2021 06:40:07 GMT
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
  int n, k;
  cin >> n >> k;
  segtree st(n + 1);
  for (int i = 1; i <= n; i++) {
    st.modify(1, 1, n, i, 1);
  }
  int id = -1;
  for (int cur = n; cur > 0; cur--) {
    id = (id + k + 1) % cur;
    int nid = st.get(1, 1, n, id + 1);
    st.modify(1, 1, n, nid, 0);
    id -= 1;
    cout << nid << " \n"[cur == 1];
  }
  return 0;
}
