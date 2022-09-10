/**
 *    author:  willy
 *    created: Mon, 13 Dec 2021 07:45:26 GMT
**/
#include <bits/stdc++.h>

using namespace std;

vector<int> kmp_table(const string& s) {
  const int n = (int) s.size();
  vector<int> p(n, 0);
  int k = 0;
  for (int i = 1; i < n; i++) {
    while (k > 0 && s[i] != s[k]) {
      k = p[k - 1];
    }
    if (s[i] == s[k]) {
      ++k;
    }
    p[i] = k;
  }
  return p;
}

vector<int> kmp_search(const string& s, const string& w, const vector<int>& p) {
  const int n = (int) s.size();
  const int m = (int) w.size();
  assert((int) p.size() == n);
  vector<int> res;
  int k = 0;
  for (int i = 0; i < m; i++) {
    while (k > 0 && (k == n || w[i] != s[k])) {
      k = p[k - 1];
    }
    if (w[i] == s[k]) {
      ++k;
    }
    if (k == n) {
      res.push_back(i - n + 1);
    }
  }
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    string s;
    cin >> s;
    int q;
    cin >> q;
    while (q--) {
      string w;
      cin >> w;
      auto k = kmp_table(w);
      auto res = kmp_search(w, s, k);
      cout << (int) res.size() << '\n';
    }
  }
  return 0;
}
