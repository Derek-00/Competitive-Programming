/**
 *    author:  wy
 *    created: Thu, 21 Jul 2022 07:18:09 GMT
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "C:\Users\wy\C++\solve\_debug\debug.h"
#else
#define debug(...) 42
#endif

const int N = 100010;

int n, k;
int a[N], p[N], sz[N];
multiset<int> s;

inline int get(int x) {
  return (x == p[x] ? x : (p[x] = get(p[x])));
}

void Unite(int x, int y) {
  x = get(x);
  y = get(y);
  if (x != y) {
    if (sz[x] < sz[y]) {
      swap(x, y);
    }
    p[y] = x;
    s.erase(s.find(sz[x]));
    s.erase(s.find(sz[y]));
    sz[x] += sz[y];
    s.insert(sz[x]);
  }
}

int main() {
  scanf("%d %d", &n, &k);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    p[i] = i;
    sz[i] = a[i];
    if (a[i] == 1) {
      s.insert(1);
    }
  }
  for (int i = 2; i <= n; i++) {
    if (a[i - 1] == 1 && a[i] == 1) {
      Unite(i - 1, i);
    }
  }
  long long sum_mx = *prev(s.end());
  long long sum_mn = *s.begin();
  while (k--) {
    int id;
    scanf("%d", &id);
    if (a[id] == 1) {
      continue;
    }
    a[id] = sz[id] = 1;
    s.insert(sz[id]);
    if (a[id + 1] == 1) {
      Unite(id, id + 1);
    }
    if (a[id - 1] == 1) {
      Unite(id - 1, id);
    }
    sum_mx += *prev(s.end());
    sum_mn += *s.begin();
  }
  printf("%lld\n%lld\n", sum_mx, sum_mn);
  return 0;
}
