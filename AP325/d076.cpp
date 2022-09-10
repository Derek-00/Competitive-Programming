/**
 *    author:  wy
 *    created: Thu, 14 Jul 2022 14:00:40 GMT
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "C:\Users\wy\C++\solve\_debug\debug.h"
#else
#define debug(...) 42
#endif

const int md = (int) 1e9 + 9;

int n;
long long p[200];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  p[0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < i; j++) {
      p[i] = (p[i] + p[j] * p[i - j - 1] % md) % md;
    }
  }
  cout << p[n] << '\n';
  return 0;
}
