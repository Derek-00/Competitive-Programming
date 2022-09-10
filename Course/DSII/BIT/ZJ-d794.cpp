/**
 *    author:  willy
 *    created: Thu, 21 Oct 2021 13:39:21 GMT
**/
#include <bits/stdc++.h>

using namespace std;

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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  while (cin >> n) {
    fenwick<int> fenw(n);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    vector<int> hash(a.begin(), a.end());
    sort(hash.begin(), hash.end());
    for (int i = 0; i < n; i++) {
      int id = (int) (lower_bound(hash.begin(), hash.end(), a[i]) - hash.begin());
      cout << (i + 1) - fenw.get(id) << '\n';
      fenw.modify(id, 1);
    }
  }
  return 0;
}
