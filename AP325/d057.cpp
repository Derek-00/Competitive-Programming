/**
 *    author:  wy
 *    created: Mon, 11 Jul 2022 04:22:53 GMT
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "C:\Users\wy\C++\solve\_debug\debug.h"
#else
#define debug(...) 42
#endif

const int N = (int) 1e5;

int n;
long long sum;
long long t[N], d[N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> t[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> d[i];
    sum += d[i];
  }
  sort(t, t + n);
  for (int i = 0; i < n; i++) {
    sum -= t[i] * (n - i);
  }
  cout << sum << '\n';
  return 0;
}
