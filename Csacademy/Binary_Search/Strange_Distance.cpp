/**
 *    author:  willy
 *    created: Mon, 10 Jan 2022 15:37:03 GMT
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "C:\Users\wy\C++\solve\_debug\debug.h"
#else
#define debug(...) 42
#endif

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
  long long k;
  cin >> n >> k;
  vector<pair<int, int>> p(n);
  for (int i = 0; i < n; i++) {
    cin >> p[i].first >> p[i].second;
  }
  sort(p.begin(), p.end());
  const int MAX = (int) 1e5;
  auto Get = [&](int dist) -> long long {
    fenwick<int> fenw(MAX + 2);
    long long res = 0;
    int l = 0;
    for (int r = 0; r < n; r++) {
      while (p[r].first - p[l].first > dist) {
        fenw.modify(p[l].second, 1);
        ++l;
      }
      res += r - l;
      if (p[r].second + dist >= 0) {
        res += fenw.get(min(MAX + 1, p[r].second + dist));
      }
      if (p[r].second - dist - 1 >= 0) {
        res -= fenw.get(min(MAX + 1, p[r].second - dist - 1));
      }
    }
    return res;
  };
  if (Get(0) >= k) {
    cout << 0 << '\n';
    return 0;
  }
  int low = 0;
  int high = MAX;
  while (low < high) {
    int mid = (low + high + 1) >> 1;
    if (Get(mid) < k) {
      low = mid;
    } else {
      high = mid - 1;
    }
  }
  cout << low + 1 << '\n';
  return 0;
}
