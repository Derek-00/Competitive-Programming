/**
 *    author:  willy
 *    created: Wed, 01 Dec 2021 11:42:45 GMT
**/
#include <bits/stdc++.h>

using namespace std;

vector<int> z_function(const string& s) {
  const int n = (int) s.size();
  vector<int> z(n, n);
  z[0] = 0;
  int l = 0, r = 0;
  for (int i = 1; i < n; i++) {
    z[i] = (i > r ? 0 : min(r - i + 1, z[i - l]));
    while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
      z[i]++;
    }
    if (i + z[i] - 1 > r) {
      l = i;
      r = i + z[i] - 1;
    }
  }
  return z;
}

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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  auto z = z_function(s);
  for (int i = 0; i < (int) z.size(); i++) {
    if (i > 0) {
      cout << " ";
    }
    cout << z[i];
  }
  cout << '\n';
  auto p = kmp_table(s);
  for (int i = 0; i < (int) p.size(); i++) {
    if (i > 0) {
      cout << " ";
    }
    cout << p[i];
  }
  cout << '\n';
  return 0;
}
