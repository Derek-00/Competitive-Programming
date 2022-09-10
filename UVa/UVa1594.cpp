#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    int counter = 0;
    bool ans = false;
    while (counter <= 1000) {
      vector<int> tmp = a;
      bool is_zero = true;
      for (int i = 0; i < n; i++) {
        a[i] = abs((i + 1 >= n ? tmp[0] : tmp[i + 1]) - tmp[i]);
        if (a[i] != 0) is_zero = false;
      }
      if (is_zero) {
        ans = true;
        break;
      }
      counter++;
    }
    cout << (ans ? "ZERO\n" : "LOOP\n");
  }
  return 0;
}
