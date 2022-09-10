/**
 *    author:  willy
 *    created: Thu, 12 Aug 2021 08:37:55 GMT
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  while (cin >> n >> m) {
    if (n == 0 && m == 0) {
      break;
    }
    string s = "";
    for (int i = 0; i < n; i++) {
      string x;
      cin >> x;
      s += x;
    }
    for (int i = 0; i < m; i++) {
      int id;
      cin >> id;
      cout << s[id - 1];
    }
    cout << '\n';
  }
  return 0;
}
