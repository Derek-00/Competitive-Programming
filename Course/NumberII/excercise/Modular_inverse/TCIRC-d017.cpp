/**
 *    author:  willy
 *    created: Sat, 30 Oct 2021 15:55:22 GMT
**/
#include <bits/stdc++.h>

using namespace std;

long long power(long long x, int k, int md) {
  long long res = 1;
  while (k > 0) {
    if (k & 1) {
      res = 1LL * res * x % md;
    }
    x = 1LL * x * x % md;
    k >>= 1;
  }
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, p;
  cin >> n >> p;
  for (int i = 0; i < n; i++) {
    long long x;
    cin >> x;
    cout << power(x, p - 2, p) << " \n"[i == n - 1];
  }
  return 0;
}
