#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  while (cin >> tt && tt) {
    while (tt--) {
      int x, y, p;
      cin >> x >> y >> p;
      int ans = 1;
      while (y) {
        if (y & 1) ans = ((ans % p) * (x % p)) % p;
        x = pow(x % p, 2);
        y >>= 1;
      }
      cout << ans << '\n';
    }
  }
  return 0;
}
