/**
 *    author:  willy
 *    created: Sat, 25 Dec 2021 16:31:53 GMT
**/
#include <bits/stdc++.h>

using namespace std;

#define int long long

int md;

inline int add(int a, int b) {
  a += b;
  if (a >= md) a -= md;
  return a;
}

inline int sub(int a, int b) {
  a -= b;
  if (a < 0) a += md;
  return a;
}

inline int mul(int a, int b) {
  return (int) ((long long) a * b % md);
}

inline int power(int a, long long b) {
  int res = 1;
  while (b > 0) {
    if (b & 1) {
      res = mul(res, a);
    }
    a = mul(a, a);
    b >>= 1;
  }
  return res;
}

inline int inverse(int a) {
  return power(a, md - 2);
}

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int a, b, x1, y1, x2, y2;
    cin >> md >> a >> b >> x1 >> y1 >> x2 >> y2;
    int m = (y2 - y1) * inverse(x2 - x1) % md;
    if (m < 0) m += md;
    int k = y1 - m * x1 % md;
    if (k < 0) k += md;
    int x3 = ((m * m % md) - x1 - x2 + md + md) % md;
    int y3 = (m * x3 + k) % md;
    cout << x3 << " " << y3 << '\n';
  }
  return 0;
}
