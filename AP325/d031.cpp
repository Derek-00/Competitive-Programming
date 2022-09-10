/**
 *    author:  wy
 *    created: Thu, 07 Jul 2022 16:03:51 GMT
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "C:\Users\wy\C++\solve\_debug\debug.h"
#else
#define debug(...) 42
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int l = 0;
  int sum = 0;
  int ans = 0, cnt = 0;
  for (int r = 0; r < n; r++) {
    sum += a[r];
    while (sum > k) {
      sum -= a[l++];
    }
    if (sum > ans) {
      ans = sum;
      cnt = 1;
    } else {
      if (sum == ans) {
        cnt += 1;        
      }
    }
  }
  cout << ans << '\n';
  cout << cnt << '\n';
  return 0;
}
