#include <bits/stdc++.h>

using namespace std;

#define int long long

int p;
int exp(int x, int y);

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int x, y;
  cin >> x >> y >> p;
  cout << exp(x, y);
  return 0;
}

int exp(int x, int y) {
  if (y == 0) return 1;
  if (y & 1) return (exp(x, y - 1) * x) % p;
  int t = exp(x, y >> 1) % p;
  return t * t % p;
}
