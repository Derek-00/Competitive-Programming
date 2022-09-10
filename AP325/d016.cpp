/**
 *    author:  wy
 *    created: Mon, 04 Jul 2022 16:30:37 GMT
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
  int n, m;
  cin >> n >> m;
  vector<int> a(m);
  for (int i = 0; i < m; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < (int) s.size(); j++) {
      int id = (int) (s[j] - 'A');
      a[i] |= (1 << id);
    }
  }
  int s = 0;
  for (int i = 0; i < n; i++) {
    s |= (1 << i);
  }
  sort(a.begin(), a.end());
  int ans = 0;
  for (int i = 0; i < m; i++) {
    if (binary_search(a.begin(), a.end(), s ^ a[i])) {
      ans += 1;
    }
  }
  cout << ans / 2 << '\n';
  return 0;
}
