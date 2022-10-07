/**
 *    author:  wy
 *    created: Fri, 07 Oct 2022 15:16:51 GMT
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
  int n, m, x, y;
  cin >> n >> m >> x >> y;
  int low = 0;
  int high = n;
  auto Can = [&](int e) {
    long long have = m + (long long) (n - e) * y;
    long long cost = (long long) e * x;
    return cost <= have;
  };
  while (low < high) {
    int mid = (low + high + 1) >> 1;
    if (Can(mid)) {
      low = mid;
    } else {
      high = mid - 1;
    }
  }
  cout << low << '\n';
  return 0;
}
