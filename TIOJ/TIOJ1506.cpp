/**
 *    author:  willy
 *    created: Tue, 31 Aug 2021 14:59:07 GMT
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed << setprecision(2);
  double a1, a2, b1, b2;
  cin >> a1 >> a2 >> b1 >> b2;
  double ans_x = 1.0 * (-(b1 - b2)) / (a1 - a2);
  double ans_y = 1.0 * a1 * ans_x + b1;
  cout << ans_x << '\n';
  cout << ans_y << '\n';
  return 0;
}
