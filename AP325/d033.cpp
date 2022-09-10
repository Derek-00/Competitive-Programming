/**
 *    author:  wy
 *    created: Fri, 08 Jul 2022 07:09:37 GMT
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "C:\Users\wy\C++\solve\_debug\debug.h"
#else
#define debug(...) 42
#endif

const int N = 200010;

int a[N], cnt[N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, l;
  cin >> n >> l;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int ans = 0;
  int mx = (int) -1e9;
  for (int i = 0; i < l; i++) {
    if (cnt[a[i]]++ == 0) {
      ans += 1;
    }
    mx = ans;
  }
  for (int r = l; r < n; r++) {
    if (cnt[a[r]]++ == 0) {
      ans += 1;
    }
    if (--cnt[a[r - l]] == 0) {
      ans -= 1;
    }
    mx = max(mx, ans);
  }
  cout << mx << '\n';
  return 0;
}
