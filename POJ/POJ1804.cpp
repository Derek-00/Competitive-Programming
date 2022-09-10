/**
 *    author:  wy
 *    created: Sun, 03 Jul 2022 14:16:18 GMT
**/
#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;


const int N = 1010;

int x[N], y[N];

int Solve(int l, int r) {   // [l, r)
  if (r - l <= 1) {
    return 0;
  }
  int mid = (l + r) >> 1;
  int ans = Solve(l, mid) + Solve(mid, r);
  copy(x + l, x + r, y + l);
  int a = l, b = mid;
  int i = l;
  while (a < mid || b < r) {
    if ((a < mid && y[a] <= y[b]) || b >= r) {
      x[i++] = y[a++];
    } else {
      ans += mid - a;
      x[i++] = y[b++];
    }
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  for (int qq = 1; qq <= tt; qq++) {
    if (qq > 1) {
      cout << '\n';
    }
    memset(x, 0, sizeof(x));
    memset(y, 0, sizeof(y));
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> x[i];
    }
    cout << "Scenario #" << qq << ':' << '\n';
    cout << Solve(0, n) << '\n';
  }
  return 0;
}
