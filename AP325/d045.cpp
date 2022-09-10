/**
 *    author:  wy
 *    created: Fri, 08 Jul 2022 11:28:28 GMT
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
pair<int, int> a[N];

inline bool Cmp(pair<int, int> x, pair<int, int> y) {
  return x.second < y.second;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i].first >> a[i].second;
  }
  sort(a, a + n, Cmp);
  int end = -1;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (a[i].first > end) {
      end = a[i].second;
      ans += 1;
    }
  }
  cout << ans << '\n';
  return 0;
}
