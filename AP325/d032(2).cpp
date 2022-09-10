/**
 *    author:  wy
 *    created: Fri, 08 Jul 2022 06:57:17 GMT
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "C:\Users\wy\C++\solve\_debug\debug.h"
#else
#define debug(...) 42
#endif

const int N = 200010;

int a[N];
int mx[N], mn[N];
int la, ra;
int lb, rb;

void Insert_mx(int id) {
  while (la < ra && a[mx[ra - 1]] < a[id]) {
    ra -= 1;
  }
  mx[ra++] = id;
}

void Insert_mn(int id) {
  while (lb < rb && a[mn[rb - 1]] > a[id]) {
    rb -= 1;
  }
  mn[rb++] = id;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, l;
  cin >> n >> l;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  la = lb = 0;
  ra = rb = 1;
  int ans = (int) -1e9;
  for (int i = 1; i < n; i++) {
    if (mx[la] <= i - l) {
      la += 1;
    }
    Insert_mx(i);
    if (mn[lb] <= i - l) {
      lb += 1;
    }
    Insert_mn(i);
    ans = max(ans, a[mx[la]] - a[mn[lb]]);
  }
  cout << ans << '\n';
  return 0;
}
