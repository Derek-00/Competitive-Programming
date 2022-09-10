/**
 *    author:  wy
 *    created: Wed, 13 Jul 2022 09:34:07 GMT
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "C:\Users\wy\C++\solve\_debug\debug.h"
#else
#define debug(...) 42
#endif

const int N = 210;

int n, m;
int a[N][N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }
  for (int j = 1; j < m; j++) {
    a[0][j] += a[0][j - 1];
  }
  for (int i = 1; i < n; i++) {
    a[i][0] += a[i - 1][0];
  }
  for (int i = 1; i < n; i++) {
    for (int j = 1; j < m; j++) {
      a[i][j] += max(a[i - 1][j], a[i][j - 1]);
    }
  }
  cout << a[n - 1][m - 1] << '\n';
  return 0;
}
