/**
 *    author:  willy
 *    created: Tue, 30 Nov 2021 05:10:17 GMT
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
  int n;
  cin >> n;
  vector<string> s(n);
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  string ans = s[0];
  for (int i = 1; i < n; i++) {
    string w = s[i] + '$' + ((int) ans.size() <= (int) s[i].size() ? ans : ans.substr(ans.size() - s[i].size()));
    auto p = kmp_table(w);
    ans += s[i].substr(p.back());
  }
  cout << ans << '\n';
  return 0;
}
