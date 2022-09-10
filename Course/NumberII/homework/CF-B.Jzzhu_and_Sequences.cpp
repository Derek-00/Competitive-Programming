/**
 *    author:  willy
 *    created: Mon, 01 Nov 2021 12:02:14 GMT
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  // f[i] = f[i - 1] - f[i - 2], i = 3
  // f[i + 1] = f[i] - f[i - 1] = (f[i - 1] - f[i - 2]) - f[i - 1] = -f[i - 2], i = 4
  // f[i + 2] = f[i + 1] - f[i] = -f[i - 2] - f[i - 1] + f[i - 2] = -f[i - 1], i = 5
  // f[i + 3] = f[i + 2] - f[i + 1] = -f[i - 1] - (-f[i - 2]) = -f[i - 1] + f[i - 2], i = 6 % 6 = 0
  // f[i + 4] = f[i + 3] - f[i + 2] = (-f[i - 1] + f[i - 2]) - (-f[i - 1]) = f[i - 2], i = 1
  // f[i + 5] = f[i + 4] - f[i + 3] = f[i - 2] + f[i - 1] - f[i - 2] = f[i - 1], i = 2
  /* ---------------------------------------------------- */
  // f[i + 6] = f[i + 5] - f[i + 4] = f[i - 1] - f[i - 2]
  // x = f[i - 2], y = f[i - 1]
  long long md = (long long) 1e9 + 7;
  long long x, y;
  cin >> x >> y;
  long long n;
  cin >> n;
  n %= 6;
  if (n == 0) {
    cout << ((-y + x) % md + md) % md << '\n';
  }
  if (n == 1) {
    cout << (x % md + md) % md << '\n';
  }
  if (n == 2) {
    cout << (y % md + md) % md << '\n';
  }
  if (n == 3) {
    cout << ((y - x) % md + md) % md << '\n';
  }
  if (n == 4) {
    cout << (-x % md + md) % md << '\n';
  }
  if (n == 5) {
    cout << (-y % md + md) % md << '\n';
  }
  return 0;
}
