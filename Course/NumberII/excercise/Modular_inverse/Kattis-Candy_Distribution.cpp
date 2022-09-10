/**
 *    author:  willy
 *    created: Sun, 31 Oct 2021 07:36:54 GMT
**/
#include <bits/stdc++.h>

using namespace std;

template<typename T>
T extgcd(T a, T b, T &x, T &y) {
  if (a == 0) {
    x = 0;
    y = 1;
    return b;
  }
  T p = b / a;
  T g = extgcd(b - p * a, a, y, x);
  x -= p * y;
  return g;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    long long n, a;
    cin >> n >> a;
    if (n == 1) {
      cout << (a > 1 ? 1 : 2) << '\n';
    } else {
      if (a == 1) {
        cout << n + 1 << '\n';
      } else {
        long long x, y;
        auto g = extgcd(a, n, x, y);
        if (g == 1) {
          cout << (x + n) % n << '\n';
        } else {
          cout << "IMPOSSIBLE" << '\n';
        }
      }
    }
  }
  return 0;
}
