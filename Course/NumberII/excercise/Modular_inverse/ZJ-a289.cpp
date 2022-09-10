/**
 *    author:  willy
 *    created: Sun, 31 Oct 2021 07:21:07 GMT
**/
#include <bits/stdc++.h>

using namespace std;

#define int long long

pair<int, int> extgcd(int a, int b) {
  if (b == 0) {
    return make_pair(1, 0);
  }
  auto p = extgcd(b, a % b);
  int nx = p.first;
  int ny = p.second;
  int x = ny;
  int y = nx - a / b * ny;
  return make_pair(x, y);
}

int mod_inv(int a, int m) {
  auto xy = extgcd(a, m);
  int x = xy.first;
  return (x % m + m) % m;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int a, n;
  while (cin >> a >> n) {
    int b = mod_inv(a, n);
    if (a * b % n == 1) {
      cout << b << '\n';
    } else {
      cout << "No Inverse" << '\n';
    }
  }
  return 0;
}
