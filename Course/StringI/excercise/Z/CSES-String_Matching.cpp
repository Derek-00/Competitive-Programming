/**
 *    author:  willy
 *    created: Wed, 01 Dec 2021 11:54:48 GMT
**/
#include <bits/stdc++.h>

using namespace std;

vector<int> z_function(int n, const string& s) {
  vector<int> z(n, n);
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

vector<int> z_function(const string& s) {
  return z_function((int) s.size(), s);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  string w;
  cin >> w;
  s = w + '$' + s;
  auto z = z_function(s);
  int ans = 0;
  for (int i = (int) w.size() + 1; i < (int) z.size(); i++) {
    if (z[i] == (int) w.size()) {
      ++ans;
    }
  }
  cout << ans << '\n';
  return 0;
}
