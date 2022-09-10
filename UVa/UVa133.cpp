#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k, m;
  while (cin >> n >> k >> m) {
    if (n == 0 && k == 0 && m == 0) {
      return 0;
    }
    vector<bool> a(n, true);
    auto move = [&](int p, int d, int t) {
      while (t--) {
        do {
          p = (p + d + n) % n;
        } while (a[p] == false);
      }
      return p;
    };
    int x = n - 1, y = 0;
    int left = n;
    while (left) {
      x = move(x, 1, k);
      y = move(y, -1, m);
      cout << setw(3) << x + 1; left--;
      if (y != x) {
        cout << setw(3) << y + 1;
        left--;
      }
      a[x] = false; a[y] = false;
      if (left) {
        cout << ',';
      }
    }
    cout << '\n';
  }
  return 0;
}
