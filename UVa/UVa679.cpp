#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  while (cin >> tt && tt != -1) {
    while (tt--) {
      int D, I;
      cin >> D >> I;
      int k = 1;
      for (int i = 0; i < D - 1; i++) {
        if (I & 1) {
          k <<= 1;
          I = (I + 1) >> 1;
        } else {
          k = k * 2 + 1;
          I >>= 1;
        }
      }
      cout << k << '\n';
    }
  }
  return 0;
}
