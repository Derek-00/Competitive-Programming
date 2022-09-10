/**
 *    author:  wy
 *    created: Fri, 08 Jul 2022 11:25:00 GMT
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
int a[N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n);
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    ans += 1LL * a[i] * (n - i);
  }
  cout << ans << '\n';
  return 0;
}
