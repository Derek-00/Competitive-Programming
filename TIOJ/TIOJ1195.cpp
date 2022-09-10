/**
 *    author:  willy
 *    created: Sun, 05 Sep 2021 15:22:00 GMT
**/
#include <bits/stdc++.h>

using namespace std;

inline int get(string s) {
  if (s[0] == s[1] && s[1] == s[2] && s[2] == s[3]) {
    return 2000;
  }
  if (s[1] == s[2] && (s[0] == s[1] || s[2] == s[3])) {
    return 1000;
  }
  if (s[0] == s[1] && s[2] == s[3]) {
    return 1500;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    ans += get(s.substr(2));
  }
  cout << ans << '\n';
  return 0;
}
