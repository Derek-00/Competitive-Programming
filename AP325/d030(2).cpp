/**
 *    author:  wy
 *    created: Thu, 07 Jul 2022 09:12:48 GMT
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "C:\Users\wy\C++\solve\_debug\debug.h"
#else
#define debug(...) 42
#endif

const int N = 100010;
const int inf = (int) 1e9;

int c[N], h[N];
vector<int> stk(1, 0);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, l;
  cin >> n >> l;
  for (int i = 1; i <= n; i++) {
    cin >> c[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> h[i];
  }
  c[0] = 0; h[0] = inf;
  c[n + 1] = l; h[n + 1] = inf;
  int ans = 0;
  int mx = 0;
  for (int i = 1; i <= n; i++) {
    if (c[stk.back()] <= c[i] - h[i] || c[i] + h[i] <= c[i + 1]) {
      ans += 1;
      mx = max(mx, h[i]);
      while (c[stk.back()] + h[stk.back()] <= c[i + 1]) {
        ans += 1;
        mx = max(mx, h[stk.back()]);
        stk.pop_back();
      }
    } else {
      stk.push_back(i);
    }
  }
  cout << ans << '\n';
  cout << mx << '\n';
  return 0;
}
