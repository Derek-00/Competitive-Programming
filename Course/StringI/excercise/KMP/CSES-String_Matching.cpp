/**
 *    author:  willy
 *    created: Mon, 29 Nov 2021 14:25:38 GMT
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
      k++;
    }
    p[i] = k;
  }
  return p;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s, w;
  cin >> s >> w;
  s = w + '$' + s;
  auto p = kmp_table(s);
  int ans = 0;
  for (int i = 0; i < (int) p.size(); i++) {
    if (p[i] == (int) w.size()) {
      ++ans;
    }
  }
  cout << ans << '\n';
  return 0;
}
