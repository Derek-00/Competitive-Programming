#include <bits/stdc++.h>

using namespace std;

bool solve(int& w) {
  int w1, d1, w2, d2;
  bool b1 = true, b2 = true;
  cin >> w1 >> d1 >> w2 >> d2;
  if (w1 == 0) b1 = solve(w1);
  if (w2 == 0) b2 = solve(w2);
  w = w1 + w2;
  return b1 && b2 && (w1 * d1 == w2 * d2);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt, w;
  cin >> tt;
  while (tt--) {
    cout << (solve(w) ? "YES\n" : "NO\n");
    if (tt) cout << '\n';
  }
  return 0;
}
