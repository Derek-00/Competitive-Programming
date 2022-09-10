/**
 *    author:  willy
 *    created: Tue, 10 Aug 2021 15:08:20 GMT
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

const int N = 100001;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  vector<pair<char, int>> q;
  vector<int> a;
  while (cin >> s) {
    if (s[0] == 'e') {
      break;
    }
    int x;
    cin >> x;
    q.emplace_back(s[0], x);
    if (s[0] != 'a') {
      a.push_back(x);
    }
  }
  sort(a.begin(), a.end());
  a.resize(unique(a.begin(), a.end()) - a.begin());
  fenwick<int> fenw(N);
  vector<bool> has(N, false);
  int sz = 0;
  for (const auto &e : q) {
    int val = e.second;
    char op = e.first;
    if (op == 'i') {
      int id = (int) (lower_bound(a.begin(), a.end(), val) - a.begin());
      if (!has[id]) {
        fenw.modify(id, 1);
        has[id] = true;
        sz++;
      }
    }
    if (op == 'r') {
      int id = (int) (lower_bound(a.begin(), a.end(), val) - a.begin());
      if (has[id]) {
        fenw.modify(id, -1);
        has[id] = false;
        sz--;
      }
    }
    if (op == 'a') {
      if (sz < val || val < 1) {
        cout << "error" << '\n';
        continue;
      }
      int l = 0, r = N - 1;
      while (l < r) {
        int m = (l + r) >> 1;
        int pref = fenw.get(m);
        if (pref < val) {
          l = m + 1;
        } else {
          r = m;
        }
      }
      cout << a[l] << '\n';
    }
  }
  return 0;
}
