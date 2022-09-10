/**
 *    author:  willy
 *    created: Sun, 08 Aug 2021 13:59:08 GMT
**/
#include <bits/stdc++.h>

using namespace std;

const int n = 26;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  vector<bool> fail(n);
  while (tt--) {
    string s;
    cin >> s;
    vector<int> cnt(n);
    for (int j = 0; j < (int) s.size(); j++) {
      cnt[s[j] - 'a']++;
    }
    for (int j = 0; j < n; j++) {
      if (cnt[j] == 0) {
        fail[j] = true;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    if (!fail[i]) {
      cout << (char) ('a' + i) << '\n';
      return 0;
    }
  }
  cout << 7122 << '\n';
  return 0;
}
