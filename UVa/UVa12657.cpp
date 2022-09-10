#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  int kase = 0;
  while (cin >> n >> m) {
    vector<int> right(n + 1);
    vector<int> left(n + 1);
    for (int i = 1; i <= n; i++) {
      left[i] = i - 1;
      right[i] = (i + 1) % (n + 1);
    }
    left[0] = n; right[0] = 1;
    auto link = [&](int l, int r) {
      right[l] = r; left[r] = l;
    };
    int op, x, y;
    bool inv = false;
    while (m--) {
      cin >> op;
      if (op == 4) {
        inv = !inv;
      } else {
        cin >> x >> y;
        if (op == 3 && right[y] == x) swap(x, y);
        if (op != 3 && inv) op = 3 - op;
        if (op == 1 && left[y] == x) continue;
        if (op == 2 && right[y] == x) continue;
        int lx = left[x], rx = right[x], ly = left[y], ry = right[y];
        if (op == 1) {
          link(lx, rx); link(ly, x); link(x, y);
        } else if (op == 2) {
          link(lx, rx); link(y, x); link(x, ry);
        } else if (op == 3) {
          if (right[x] == y) {
            link(lx, y); link(y, x); link(x, ry);
          } else {
            link(lx, y); link(y, rx); link(ly, x); link(x, ry);
          }
        }
      }
    }
    int b = 0;
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
      b = right[b];
      if (i & 1) ans += b;
    }
    if (inv && n % 2 == 0) ans = (long long) n * (n + 1) / 2 - ans;
    cout << "Case " << ++kase << ": " << ans << '\n';
  }
  return 0;
}
