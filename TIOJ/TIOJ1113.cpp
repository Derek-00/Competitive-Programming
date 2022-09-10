/**
 *    author:  willy
 *    created: Tue, 10 Aug 2021 16:04:50 GMT
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  while (cin >> s) {
    sort(s.begin(), s.end());
    do {
      cout << s << '\n';
    } while (next_permutation(s.begin(), s.end()));
    cout << '\n';
  }
  return 0;
}
