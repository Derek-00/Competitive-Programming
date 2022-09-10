/**
 *    author:  willy
 *    created: Tue, 10 Aug 2021 16:25:27 GMT
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  unsigned long long n, m;
  while (cin >> n >> m) {
    if (n == 0 && m == 0) {
      break;
    }
    if (n > m) {
      swap(n, m);
    }
    cout << n * m + n * n * m - (n + m) * (n * (n + 1) / 2) + (n * (n + 1) * (2 * n + 1)) / 6 << '\n';
  }
  return 0;
}
