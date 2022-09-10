/**
 *    author:  willy
 *    created: Sat, 14 Aug 2021 09:36:28 GMT
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string p, q;
  cin >> p >> q;
  for (int i = 0; i < (int) q.size(); i++) {
    bool match = true;
    for (int j = 0; i + j < (int) q.size(); j++) {
      if (j >= (int) p.size() || p[j] != q[i + j]) {
        match = false;
        break;
      }
    }
    if (match) {
      cout << (int) q.size() - i << '\n';
      return 0;
    }
  }
  cout << 0 << '\n';
  return 0;
}
