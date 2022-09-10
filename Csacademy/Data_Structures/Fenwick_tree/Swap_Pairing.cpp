/**
 *    author:  willy
 *    created: Tue, 28 Dec 2021 15:49:49 GMT
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
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  auto nor = normalize(a);
  for (int i = 0; i < n; i++) {
    a[i] = (int) (lower_bound(nor.begin(), nor.end(), a[i]) - nor.begin());
  }
  vector<vector<int>> pos(n);
  for (int i = 0; i < n; i++) {
    pos[a[i]].push_back(i);
  }
  fenwick<int> fenw(n);
  vector<bool> been(n);
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    if (been[a[i]]) {
      continue;
    }
    been[a[i]] = true;
    int j = pos[a[i]][1];
    ans += (long long) (j - i - 1 - fenw.get(j) + fenw.get(i));
    fenw.modify(j, 1);
  }
  cout << ans << '\n';
  return 0;
}
