/**
 *    author:  willy
 *    created: Tue, 10 Aug 2021 16:31:38 GMT
**/
#include <bits/stdc++.h>
#include "lib1044.h"

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  n = Initialize();
  int l = 1, r = n;
  while (l < r) {
    int mid = (l + r) >> 1;
    int res = Guess(mid);
    if (res == 0) {
      l = mid + 1;
    } else {
      r = mid;
    }
  }
  assert(l == r);
  Report(l);
  return 0;
}
