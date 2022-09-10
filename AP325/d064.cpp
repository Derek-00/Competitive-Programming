/**
 *    author:  wy
 *    created: Mon, 11 Jul 2022 14:52:43 GMT
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "C:\Users\wy\C++\solve\_debug\debug.h"
#else
#define debug(...) 42
#endif

const int N = 100010;

int n;
int a[N], saved[N];

long long Solve(int l, int r) {
  if (l >= r - 1) {
    return 0;
  }
  int m = (l + r) >> 1;
  long long ans = Solve(l, m) + Solve(m, r);
  long long cross = 0;
  int j = m, k = 0;
  for (int i = l; i < m; i++) {
    while (j < r && a[i] > a[j]) {
      saved[k] = a[j];
      ++k; ++j;
    }
    saved[k++] = a[i];
    cross += j - m;
  }
  for (int i = l; i < j; i++) {
    a[i] = saved[i - l];
  }
  return ans + cross;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  cout << Solve(0, n) << '\n';
  return 0;
}
