/**
 *    author:  wy
 *    created: Fri, 08 Jul 2022 07:35:15 GMT
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "C:\Users\wy\C++\solve\_debug\debug.h"
#else
#define debug(...) 42
#endif

const int N = 200010;

int n;
int a[N], b[N];
int cnt[N];

void Hash() {
  copy(a, a + n, b);
  sort(b, b + n);
  int m = (int) (unique(b, b + n) - b);
  for (int i = 0; i < n; i++) {
    a[i] = (int) (lower_bound(b, b + m, a[i]) - b);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  Hash();
  int l = 0;
  int ans = 0;
  for (int r = 0; r < n; r++) {
    cnt[a[r]] += 1;
    while (cnt[a[r]] >= 2) {
      cnt[a[l]] -= 1;
      l += 1;
    }
    ans = max(ans, r - l + 1);
  }
  cout << ans << '\n';
  return 0;
}
