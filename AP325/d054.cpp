/**
 *    author:  wy
 *    created: Sat, 09 Jul 2022 16:13:40 GMT
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "C:\Users\wy\C++\solve\_debug\debug.h"
#else
#define debug(...) 42
#endif

int n, m;
long long p[100010];

bool Can(long long f) {
  int use = m;
  long long power = f;
  for (int i = 0; i < n; i++) {
    if (power - p[i] < 0) {
      if (use <= 0 || f < p[i]) {
        return false;
      }
      use -= 1;
      power = f;
    }
    power -= p[i];
  }
  return true;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> p[i];
  }
  long long low = 0LL;
  long long high = accumulate(p, p + n, 0);
  while (low < high) {
    long long mid = (low + high + 1) >> 1;
    if (Can(mid)) {
      high = mid - 1;
    } else {
      low = mid;
    }
  }
  cout << low + 1 << '\n';
  return 0;
}
