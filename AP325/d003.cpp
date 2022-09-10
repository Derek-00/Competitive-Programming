/**
 *    author:  willy
 *    created: Sun, 01 Aug 2021 10:36:54 GMT
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 50010;

int n, l;
int p[N];

long long Get(int l, int r) {
  if (r - l <= 1) {
    return 0;
  }
  int m = (int) (lower_bound(p + l, p + r, (p[l] + p[r]) / 2) - p);
  if (p[m - 1] - p[l] >= p[r] - p[m]) {
    --m;
  }
  return (p[r] - p[l]) + Get(l, m) + Get(m, r);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> l;
  p[0] = 0; p[n + 1] = l;
  for (int i = 1; i <= n; i++) {
    cin >> p[i];
  }
  cout << Get(0, n + 1) << '\n';
  return 0;
}
