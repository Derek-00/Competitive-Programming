/**
 *    author:  willy
 *    created: Mon, 01 Nov 2021 01:29:44 GMT
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    long long n;
    cin >> n;
    if (n <= 0) {
      cout << 0 << '\n';
      continue;
    }
    long long ans = n;
    for (int i = 2; i <= n; i++) {
      if (n / i == 0) {
        break;
      }
      long long r = (long long) n / (n / i);
      ans += (n / i) * (r - i + 1);
      i = r;
    }
    cout << ans << '\n';
  }
  return 0;
}
