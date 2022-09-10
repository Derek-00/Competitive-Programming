/**
 *    author:  willy
 *    created: Tue, 07 Dec 2021 12:37:01 GMT
**/
#include <bits/stdc++.h>

using namespace std;

template<typename T>
class fenwick {
 public:
  vector<T> fenw;
  int n;

  fenwick(int _n) : n(_n) {
    fenw.resize(n);
  }

  void modify(int x, T v) {
    while (x < n) {
      fenw[x] = max(fenw[x], v);
      x |= (x + 1);
    }
  }

  T get(int x) {
    T v = 0;
    while (x >= 0) {
      v = max(v, fenw[x]);
      x = (x & (x + 1)) - 1;
    }
    return v;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    vector<int> w(n);
    for (int i = 0; i < n; i++) {
      cin >> w[i];
    }
    vector<int> new_a(a.begin(), a.end());
    sort(new_a.begin(), new_a.end());
    new_a.resize(unique(new_a.begin(), new_a.end()) - new_a.begin());
    for (int i = 0; i < n; i++) {
      a[i] = (int) (lower_bound(new_a.begin(), new_a.end(), a[i]) - new_a.begin());
    }
    long long ans = 0;
    fenwick<long long> fenw(n + 1);
    for (int i = 0; i < n; i++) {
      long long dp = fenw.get(a[i]) + w[i];
      ans = max(ans, dp);
      fenw.modify(a[i] + 1, dp);
    }
    cout << ans << '\n';
  }
  return 0;
}
