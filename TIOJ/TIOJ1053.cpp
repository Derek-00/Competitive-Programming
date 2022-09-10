/**
 *    author:  willy
 *    created: Sun, 08 Aug 2021 12:50:50 GMT
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int p, q;
  cin >> p >> q;
  cout << (max(p, q) % min(p, q) == 0 ? 'Y' : 'N') << '\n';
  return 0;
}
