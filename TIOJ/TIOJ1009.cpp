/**
 *    author:  willy
 *    created: Sun, 08 Aug 2021 10:32:28 GMT
**/
#include <bits/stdc++.h>

using namespace std;

int to_digit(string s) {
  int res = 0;
  for (int i = 0; i < (int) s.size(); i++) {
    res = res * 10 + (s[i] - '0');
  }
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s, e;
  cin >> s >> e;
  vector<int> a(3), b(3);
  a[0] = to_digit(s.substr(0, 2));
  a[1] = to_digit(s.substr(3, 2));
  a[2] = to_digit(s.substr(6, 2));
  b[0] = to_digit(e.substr(0, 2));
  b[1] = to_digit(e.substr(3, 2));
  b[2] = to_digit(e.substr(6, 2));
  vector<int> c(3);
  for (int i = 2; i >= 0; i--) {
    c[i] = b[i] - a[i];
    if (c[i] < 0) {
      if (i == 0) {
        c[i] += 24;
      } else {
        c[i] += 60;
        b[i - 1] -= 1;
      }
    }
  }
  for (int i = 0; i < 3; i++) {
    if (i > 0) {
      cout << ':';
    }
    cout << setfill('0') << setw(2) << c[i];
  }
  return 0;
}
