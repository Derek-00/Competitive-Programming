/**
 *    author:  willy
 *    created: Mon, 29 Nov 2021 15:17:09 GMT
**/
#include <bits/stdc++.h>

using namespace std;

vector<int> kmp_table(const string& s) {
  const int n = (int) s.size();
  vector<int> p(n, 0);
  int k = 0;
  for (int i = 1; i < n; i++) {
    while (k > 0 && s[k] != s[i]) {
      k = p[k - 1];
    }
    if (s[k] == s[i]) {
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
  auto p = kmp_table(s);
  vector<int> dp((int) s.size() + 1);
  for (int i = 1; i < (int) s.size(); i++) {
    ++dp[p[i]];
  }
  for (int i = (int) s.size() - 1; i >= 1; i--) {
    int nxt = p[i - 1];
    dp[nxt] += dp[i];
  }
  for (int i = 1; i < (int) s.size(); i++) {
    ++dp[i];
  }
  int id = p.back();
  vector<int> ans;
  while (id > 0) {
    ans.push_back(id);
    id = p[id - 1];
  }
  reverse(ans.begin(), ans.end());
  cout << (int) ans.size() + 1 << '\n';
  for (auto& len : ans) {
    cout << len << " " << dp[len] << '\n';
  }
  cout << (int) s.size() << " " << 1 << '\n';
  return 0;
}
