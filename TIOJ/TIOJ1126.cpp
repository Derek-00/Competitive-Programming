/**
 *    author:  willy
 *    created: Sun, 12 Sep 2021 15:35:38 GMT
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  while (cin >> s) {
    int ans = 1;
    auto is_palin = [&](string a) {
      int sz = (int) a.size();
      for (int i = 0; i < sz / 2; i++) {
        if (a[i] != a[sz - i - 1]) {
          return false;
        }
      }
      return true;
    };
    for (int i = 0; i < (int) s.size(); i++) {
      for (int j = 1; j + i - 1 < (int) s.size(); j++) {
        if (is_palin(s.substr(i, j))) {
          ans = max(ans, j);
        }
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
