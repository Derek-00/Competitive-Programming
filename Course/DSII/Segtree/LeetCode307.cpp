/**
 *    author:  willy
 *    created: Fri, 22 Oct 2021 14:04:49 GMT
**/
#include <bits/stdc++.h>

using namespace std;

class segtree {
 public:
  vector<int> a;
  vector<int> tree;
  int n;

  segtree() {
  }

  void init(const vector<int>& _a) {
    a = _a;
    n = (int) a.size();
    tree.resize(n << 2);
    build(1, 0, n - 1);
  }

  void build(int v, int l, int r) {
    if (l == r) {
      tree[v] = a[l];
      return;
    }
    int y = (l + r) >> 1;
    build(v << 1, l, y);
    build(v << 1 | 1, y + 1, r);
    tree[v] = tree[v << 1] + tree[v << 1 | 1];
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

class NumArray {
 public:
  segtree st;
  int n;

  NumArray(vector<int>& nums) : n((int) nums.size()) {
    st.init(nums);
  }

  void update(int index, int val) {
    st.modify(1, 0, n - 1, index, val);
  }

  int sumRange(int left, int right) {
    return st.get(1, 0, n - 1, left, right);
  }
};
