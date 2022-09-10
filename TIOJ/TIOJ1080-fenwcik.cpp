/**
 *    author:  willy
 *    created: Sat, 28 Aug 2021 09:34:23 GMT
**/
#include <bits/stdc++.h>

using namespace std;

#define int long long

template <typename T>
class fenwick {
 public:
  vector<T> fenw;
  int n;

  fenwick(int _n) : n(_n) {
    fenw.resize(n);
  }

  void modify(int x, T v) {
    while (x < n) {
      fenw[x] += v;
      x |= (x + 1);
    }
  }

  T get(int x) {
    T v{};
    while (x >= 0) {
      v += fenw[x];
      x = (x & (x + 1)) - 1;
    }
    return v;
  }
};

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  int Case = 0;
  while (cin >> n && n) {
    vector<int> a(n);
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      v[i] = a[i];
    }
    sort(v.begin(), v.end());
    v.resize(unique(v.begin(), v.end()) - v.begin());
    fenwick<int> fenw(n);
    int ans = 0;
    for (int i = 0; i < n; i++) {
      int id = (int) (lower_bound(v.begin(), v.end(), a[i]) - v.begin());
      ans += i - fenw.get(id); // how many a[j] > a[i], if j < i 
      fenw.modify(id, +1);
    }
    cout << "Case #" << ++Case << ": " << ans << '\n';
  }
  return 0;
}
