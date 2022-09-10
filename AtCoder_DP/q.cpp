/**
 *    author:  willy
 *    created: Fri, 10 Dec 2021 06:37:44 GMT
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
      fenw[x] = max(fenw[x], v);
      x |= (x + 1);
    }
  }

  T get(int x) {
    T v{};
    while (x >= 0) {
      v = max(v, fenw[x]);
      x = (x & (x + 1)) - 1;
    }
    return v;
  }
};

vector<int> normalize(vector<int> a) {
  sort(a.begin(), a.end());
  a.resize(unique(a.begin(), a.end()) - a.begin());
  return a;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> h(n);
  for (int i = 0; i < n; i++) {
    cin >> h[i];
  }
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  auto nor = normalize(h);
  fenwick<long long> fenw(n);
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    int id = (int) (lower_bound(nor.begin(), nor.end(), h[i]) - nor.begin());
    long long mx = (id == 0 ? 0 : fenw.get(id - 1)) + a[i];
    ans = max(ans, mx);
    fenw.modify(id, mx);
  }
  cout << ans << '\n';
  return 0;
}
