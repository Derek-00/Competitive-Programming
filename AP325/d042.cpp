/**
 *    author:  wy
 *    created: Fri, 08 Jul 2022 11:16:01 GMT
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "C:\Users\wy\C++\solve\_debug\debug.h"
#else
#define debug(...) 42
#endif

const int c[] = {1, 5, 10, 50};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int m;
  cin >> m;
  while (m--) {
    int x;
    cin >> x;
    int ans = 0;
    for (int i = 3; i >= 0; i--) {
      ans += x / c[i];
      x %= c[i];
    }
    cout << ans << '\n';
  }
  return 0;
}
