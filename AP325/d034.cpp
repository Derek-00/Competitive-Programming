/**
 *    author:  wy
 *    created: Fri, 08 Jul 2022 07:19:01 GMT
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "C:\Users\wy\C++\solve\_debug\debug.h"
#else
#define debug(...) 42
#endif

const int N = 200010;

int a[N], b[N];
int cnt[N];

int Hash(int n) {
  copy(a, a + n, b);
  sort(b, b + n);
  int m = (int) (unique(b, b + n) - b);
  for (int i = 0; i < n; i++) {
    a[i] = (int) (lower_bound(b, b + m, a[i]) - b);
  }
  return m;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int m = Hash(n);
  int l = 0;
  int ans = 0;
  int mn = n;
  for (int r = 0; r < n; r++) {
    if (cnt[a[r]]++ == 0) {
      ans += 1;
    }
    while (cnt[a[l]] >= 2) {
      cnt[a[l]] -= 1;
      l += 1;
    }
    if (ans == m) {
      mn = min(mn, r - l + 1);
    }
  }
  cout << mn << '\n';
  return 0;
}
