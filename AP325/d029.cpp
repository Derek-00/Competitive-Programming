/**
 *    author:  wy
 *    created: Thu, 07 Jul 2022 08:35:48 GMT
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "C:\Users\wy\C++\solve\_debug\debug.h"
#else
#define debug(...) 42
#endif

const int N = 200010;

int h[N], p[N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  h[0] = (int) 1e9;
  for (int i = 1; i <= n; i++) {
    cin >> h[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> p[i];
  }
  multimap<int, int> mp;
  long long ans = 0;
  for (int i = n; i >= 0; i--) {
    auto it = mp.begin();
    while (it != mp.end() && h[i] > it->first) {
      ans += it->second - i - 1;
      it = mp.erase(it);
    }
    mp.emplace(h[i] + p[i], i);
  }
  cout << ans << '\n';
  return 0;
}
