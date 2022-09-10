/**
 *    author:  wy
 *    created: Sun, 17 Jul 2022 08:24:02 GMT
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "C:\Users\wy\C++\solve\_debug\debug.h"
#else
#define debug(...) 42
#endif

int n;
multiset<int> ms;

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int s, t;
    scanf("%d %d", &s, &t);
    ms.insert(s);
    auto it = ms.upper_bound(t);
    if (it != ms.end()) {
      ms.erase(it);
    }
  }
  printf("%d\n", (int) ms.size());
  return 0;
}
