/**
 *    author:  willy
 *    created: Sat, 08 Jan 2022 08:37:30 GMT
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
  vector<int> delta(n - 1);
  for (int i = 0; i < n - 1; i++) {
    delta[i] = a[i + 1] - a[i];
  }
  int cnt = n - k;
  deque<int> d;
  int ans = (int) 1e9;
  for (int i = 0; i < n - 1; i++) {
    if (!d.empty() && i - d.front() + 1 >= cnt) {
      d.pop_front();
    }
    while (!d.empty() && delta[d.back()] <= delta[i]) {
      d.pop_back();
    }
    d.push_back(i);
    if (i + 2 >= cnt) {
      ans = min(ans, delta[d.front()]);
    }
  }
  cout << ans << '\n';
  return 0;
}
