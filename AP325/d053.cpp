/**
 *    author:  wy
 *    created: Fri, 08 Jul 2022 15:11:51 GMT
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "C:\Users\wy\C++\solve\_debug\debug.h"
#else
#define debug(...) 42
#endif

int n, m;
int t[200010];

multiset<long long> s;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> t[i];
  }
  for (int i = 0; i < min(n, m); i++) {
    s.insert(t[i]);
  }
  long long ans = 0;
  for (int i = m; i < n; i++) {
    auto it = s.begin();
    long long x = t[i] + *it;
    s.erase(it);
    s.insert(x);
    ans = max(ans, x);
  }
  cout << ans << '\n';
  return 0;
}
