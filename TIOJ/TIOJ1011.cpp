/**
 *    author:  willy
 *    created: Sat, 14 Aug 2021 09:48:49 GMT
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int a, b;
  cin >> a >> b;
  int cnt = 0;
  while (a != b) {
    if (a > b) {
      a >>= 1;
    } else {
      b >>= 1;
    }
    ++cnt;
  }
  cout << cnt << '\n';
  return 0;
}
