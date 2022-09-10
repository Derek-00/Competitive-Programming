/**
 *    author:  wy
 *    created: Sat, 09 Jul 2022 15:58:51 GMT
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "C:\Users\wy\C++\solve\_debug\debug.h"
#else
#define debug(...) 42
#endif

const int N = 50010;

int n, k;
int p[N];

bool Can(int r) {
  int segs = k;
  int end = -1;
  for (int i = 0; i < n; i++) {
    if (p[i] <= end) {
      continue;
    }
    if (segs <= 0) {
      return false;
    }
    segs -= 1;
    end = p[i] + r;
  }
  return true;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> p[i];
  }
  sort(p, p + n);
  int low = 1, high = p[n - 1] - p[0];
  while (low < high) {
    int mid = (low + high + 1) >> 1;
    if (Can(mid)) {
      high = mid - 1;
    } else {
      low = mid;
    }
  }
  cout << low + 1 << '\n';
  debug(clock());
  return 0;
}
