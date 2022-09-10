/**
 *    author:  wy
 *    created: Tue, 12 Jul 2022 13:44:30 GMT
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "C:\Users\wy\C++\solve\_debug\debug.h"
#else
#define debug(...) 42
#endif

int n;
long long a[100010];

long long Solve(int l, int r) {
  if (l >= r) return 0;
  if (r - l == 1) return a[l];
  int mid = (l + r) >> 1;
  long long ans = max(Solve(l, mid), Solve(mid + 1, r));
  long long i = mid, j = mid;
  long long h = a[mid], mx = 0;
  while (i >= l || j < r) {
    if (i < l) {
      h = a[j];
    } else {
      if (j >= r) {
        h = a[i];
      } else {
        h = max(a[i], a[j]);
      }
    }
    while (i >= l && a[i] >= h) {
      i -= 1;
    }
    while (j < r && a[j] >= h) {
      j += 1;
    }
    mx = max(mx, (j - i - 1) * h);
  }
  return max(mx, ans);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  cout << Solve(0, n) <<'\n';
  return 0;
}
