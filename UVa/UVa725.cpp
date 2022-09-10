/**
 *    author:  willy
 *    created: Tue, 17 Aug 2021 02:11:04 GMT
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  bool kase = false;
  while (cin >> n && n) {
    if (kase) {
      cout << '\n';
    } else {
      kase = true;
    }
    bool cnt = false;
    int a = 1234;
    while (true) {
      int b = a * n;
      auto Do = [&](string s) {
        if ((int) s.size() == 4) {
          s = '0' + s;
        }
        return s;
      };
      string x = Do(to_string(a));
      string y = Do(to_string(b));
      string check = x + y;
      if ((int) check.size() > 10) {
        break;
      }
      sort(check.begin(), check.end());
      check.resize(unique(check.begin(), check.end()) - check.begin());
      if ((int) check.size() == 10) {
        cnt = true;
        cout << setfill('0') << setw(5) << b <<  " / " << setfill('0') << setw(5) << a << " = " << n << '\n';
      }
      ++a;
    }
    if (!cnt) {
      cout << "There are no solutions for " << n << '.' << '\n';
    }
  }
  return 0;
}
