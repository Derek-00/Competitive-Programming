/**
 *    author:  wy
 *    created: Mon, 11 Jul 2022 06:30:49 GMT
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "C:\Users\wy\C++\solve\_debug\debug.h"
#else
#define debug(...) 42
#endif

int n, d;
int t[100010];
multiset<int> s;

bool Can(int m) {
  s.clear();
  for (int i = 0; i < m; i++) {
    s.insert(t[i]);
  }
  for (int i = m; i < n; i++) {
    auto it = s.begin();
    int x = *it + t[i];
    if (x > d) {
      return false;
    }
    s.erase(it);
    s.insert(x);
  }
  return true;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> d;
  for (int i = 0; i < n; i++) {
    cin >> t[i];
  }
  int low = 1;
  int high = n;
  while (low < high) {
    int mid = (low + high + 1) >> 1;
    if (Can(mid)) {
      high = mid - 1;
    } else {
      low = mid;
    }
  }
  cout << low + 1 << '\n';
  return 0;
}
