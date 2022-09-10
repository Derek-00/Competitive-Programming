/**
 *    author:  willy
 *    created: Sun, 31 Oct 2021 09:05:57 GMT
**/
#include <bits/stdc++.h>

using namespace std;

long long mul(long long a, long long b, long long n) {
  long long res = 0;
  while (b > 0) {
    if (b & 1) {
      res += a;
      if (res >= n) {
        res -= n;
      }
    }
    a <<= 1;
    b >>= 1;
    if (a >= n) {
      a -= n;
    }
  }
  return res;
}

long long power(long long x, long long k, long long n) {
  long long res = 1LL;
  while (k > 0) {
    if (k & 1) {
      res = mul(res, x, n);
    }
    x = mul(x, x, n);
    k >>= 1;
  }
  return res;
}

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
    long long n, m, l;
    cin >> n >> m >> l;
    long long x, y;
    extgcd(2LL, n + 1, x, y);
    x = (x + (n + 1)) % (n + 1);
    x = power(x, m, n + 1);
    cout << mul(x, l, n + 1) << '\n';
  }
  return 0;
}
