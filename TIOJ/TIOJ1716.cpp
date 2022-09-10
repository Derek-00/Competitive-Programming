/**
 *    author:  willy
 *    created: Tue, 17 Aug 2021 13:23:19 GMT
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int a, b, c;
    cin >> a >> b >> c;
    int D = b * b - 4 * a * c;
    int sq = sqrt(D);
    if (D == sq * sq) {
      cout << "Yes" << '\n';
    } else {
      cout << "No" << '\n';
    }
  }
  return 0;
}
