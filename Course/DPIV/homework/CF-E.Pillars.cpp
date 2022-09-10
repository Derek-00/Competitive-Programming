/**
 *    author:  willy
 *    created: Wed, 08 Dec 2021 14:45:10 GMT
**/
#include <bits/stdc++.h>

using namespace std;

#define int long long

class segtree {
 public:
  struct node {
    long long mx = 0;
    int id = -1;
  };

  vector<node> tree;
  int n;

  segtree(int _n) : n(_n) {
    tree.resize(2 * n - 1);
  }

  node unite(const node& a, const node& b) {
    node res;
    res = (a.mx > b.mx ? a : b);
    return res;
  }

  void pull(int x, int z) {
    tree[x] = unite(tree[x + 1], tree[z]);
  }

  void modify(int x, int l, int r, int id, node info) {
    if (l == r) {
      tree[x] = info;
      return;
    }
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    if (id <= y) {
      modify(x + 1, l, y, id, info);
    } else {
      modify(z, y + 1, r, id, info);
    }
    pull(x, z);
  }

  node get(int x, int l, int r, int ll, int rr) {
    if (ll <= l && r <= rr) {
      return tree[x];
    }
    node res{};
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    if (rr <= y) {
      res = get(x + 1, l, y, ll, rr);
    } else {
      if (ll > y) {
        res = get(z, y + 1, r, ll, rr);
      } else {
        res = unite(get(x + 1, l, y, ll, rr), get(z, y + 1, r, ll, rr));
      }
    } 
    return res;
  }
};

template<typename T>
vector<T> normalize(const vector<T> a, const T& d) {
  vector<T> res;
  for (int i = 0; i < (int) a.size(); i++) {
    res.push_back(a[i]);
    res.push_back(a[i] - d);
    res.push_back(a[i] + d);
  }
  sort(res.begin(), res.end());
  res.resize(unique(res.begin(), res.end()) - res.begin());
  return res;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, d;
  cin >> n >> d;
  vector<long long> h(n);
  for (int i = 0; i < n; i++) {
    cin >> h[i];
  }
  auto nor = normalize(h, 1LL * d);
  auto Get = [&](int v) {
    return (int) (lower_bound(nor.begin(), nor.end(), v) - nor.begin());
  };
  const int m = (int) nor.size();
  segtree st(m);
  vector<long long> dp(n);
  vector<int> prv(n, -1);
  int ls_id = -1;
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    auto ls = st.get(0, 0, m - 1, 0, Get(h[i] - d));
    auto gt = st.get(0, 0, m - 1, Get(h[i] + d), m - 1);
    if (ls.mx > gt.mx) {
      dp[i] = ls.mx + 1;
      prv[i] = ls.id;
    } else {
      dp[i] = gt.mx + 1;
      prv[i] = gt.id;
    }
    st.modify(0, 0, m - 1, Get(h[i]), {dp[i], i});
    if (ans < dp[i]) {
      ans = dp[i];
      ls_id = i;
    }
  }
  cout << ans << '\n';
  vector<int> ans_list;
  while (ans--) {
    ans_list.push_back(ls_id);
    ls_id = prv[ls_id];
  }
  reverse(ans_list.begin(), ans_list.end());
  for (int i = 0; i < (int) ans_list.size(); i++) {
    if (i > 0) {
      cout << " ";
    }
    cout << ans_list[i] + 1;
  }
  cout << '\n';
  return 0;
}
