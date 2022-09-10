/**
 *    author:  willy
 *    created: Sun, 31 Oct 2021 12:59:04 GMT
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

long long mod_inv(long long a, long long m) {
  long long x, y;
  extgcd(a, m, x, y);
  x = (x % m + m) % m;
  return x;
}

long long mul(long long a, long long b, long long md) {
  long long res = 0;
  while (b > 0) {
    if (b & 1) {
      res += a;
      if (res >= md) {
        res -= md;
      }
    }
    a <<= 1;
    b >>= 1;
    if (a >= md) {
      a -= md;
    }
  }
  return res;
}

long long power(long long x, long long k, long long md) {
  long long res = 1;
  while (k > 0) {
    if (k & 1) {
      res = mul(res, x, md);
    }
    x = mul(x, x, md);
    k >>= 1;
  }
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long c, d, p, q;
  while (cin >> c >> d >> p >> q) {
    long long n = p * q;
    long long b1 = power(c % p, __gcd(c, p) == 1 ? d % (p - 1) : d, p);
    long long b2 = power(c % q, __gcd(c, q) == 1 ? d % (q - 1) : d, q);
    long long m1 = q * mod_inv(q, p) % n;
    long long m2 = p * mod_inv(p, q) % n;
    long long m = (mul(b1, m1, n) + mul(b2, m2, n)) % n;
    cout << m << '\n';
  }
  return 0;
}
