/**
 *    author:  willy
 *    created: Sun, 31 Oct 2021 07:29:51 GMT
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
  long long a, n;
  while (cin >> a >> n) {
    long long x, y;
    auto g = extgcd(a, n, x, y);
    if (g == 1 && x != 0) {
      cout << (x % n + n) % n << '\n';
    } else {
      cout << "No Inverse" << '\n';
    }
  }
  return 0;
}
