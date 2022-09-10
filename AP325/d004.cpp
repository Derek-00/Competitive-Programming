/**
 *    author:  wy
 *    created: Mon, 04 Jul 2022 06:50:26 GMT
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "C:\Users\wy\C++\solve\_debug\debug.h"
#else
#define debug(...) 42
#endif

const int N = 50010;

int n, k;
long long p[N];
long long pref[N], pref_i[N];

long long Solve(int l, int r, int level) {
  if (r - l <= 1 || level >= k) {
    return 0;
  }
  long long mn = (long long) 9e18;
  long long sum = pref[r] - pref[l - 1];
  long long sum_i = pref_i[r] - pref_i[l - 1];
  int cut = -1;
  for (int k = l + 1; k <= r - 1; k++) {
    long long x = abs(sum_i - k * sum);
    if (x < mn) {
      cut = k;
      mn = x;
    }
  }
  return p[cut] + Solve(l, cut - 1, level + 1) + Solve(cut + 1, r, level + 1);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> p[i];
  }
  for (int i = 1; i <= n; i++) {
    pref[i] = pref[i - 1] + p[i];
    pref_i[i] = pref_i[i - 1] + p[i] * i;
  }
  cout << Solve(1, n, 0) << '\n';
  return 0;
}
