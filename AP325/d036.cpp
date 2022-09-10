/**
 *    author:  wy
 *    created: Fri, 08 Jul 2022 07:43:58 GMT
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "C:\Users\wy\C++\solve\_debug\debug.h"
#else
#define debug(...) 42
#endif

const int N = 200010;

int m, n;
int c, ans;

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
  cin >> m >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  Hash();
  for (int i = 0; i < m; i++) {
    if (cnt[a[i]]++ == 0) {
      c += 1;
    }
  }
  ans = (c == m ? 1 : 0);
  for (int i = m; i < n; i++) {
    if (cnt[a[i]]++ == 0) {
      c += 1;
    }
    if (--cnt[a[i - m]] == 0) {
      c -= 1;
    }
    if (c == m) {
      ans += 1;
    }
  }
  cout << ans << '\n';
  return 0;
}
