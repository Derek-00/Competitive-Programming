/**
 *    author:  wy
 *    created: Fri, 08 Jul 2022 11:20:45 GMT
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
int ans;
int a[N], b[N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n);
  sort(b, b + n);
  int j = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] > b[j]) {
      ans += 1;
      j += 1;
    }
  }
  cout << ans << '\n';
  return 0;
}
