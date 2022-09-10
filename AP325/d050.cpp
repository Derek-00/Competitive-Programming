/**
 *    author:  wy
 *    created: Sat, 09 Jul 2022 16:21:33 GMT
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "C:\Users\wy\C++\solve\_debug\debug.h"
#else
#define debug(...) 42
#endif

int n;
pair<int, int> p[100010];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> p[i].first >> p[i].second;
  }
  sort(p, p + n);
  int end = -1;
  int sum = 0;
  for (int i = 0; i < n; i++) {
    if (end < p[i].first) {
      sum += p[i].second - p[i].first;
      end = p[i].second;
    } else {
      sum += max(0, p[i].second - end);
      end = max(end, p[i].second);
    }
  }
  cout << sum << '\n';
  return 0;
}
