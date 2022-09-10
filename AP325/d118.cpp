/**
 *    author:  wy
 *    created: Fri, 15 Jul 2022 05:58:15 GMT
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "C:\Users\wy\C++\solve\_debug\debug.h"
#else
#define debug(...) 42
#endif

const int N = 100010;

struct Item {
  int l, r;
  int w;

  inline bool operator < (const Item& rhs) const {
    return r < rhs.r;
  }
} a[N];

int n;
int dp[N];

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d %d %d", &a[i].l, &a[i].r, &a[i].w);
  }
  sort(a + 1, a + (n + 1));
  for (int i = 1; i <= n; i++) {
    int low = 0, high = i;
    while (low < high) {
      int mid = (low + high + 1) >> 1;
      if (a[mid].r < a[i].l) {
        low = mid;
      } else {
        high = mid - 1;
      }
      dp[i] = max(dp[i - 1], dp[low] + a[i].w);
    }
  }
  printf("%d\n", dp[n]);
  return 0;
}
