#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  while (cin >> n && n) {
    vector<int> target(n + 1);
    while (cin >> target[1]) {
      if (target[1] == 0) break;
      for (int i = 2; i <= n; i++) {
        cin >> target[i];
      }
      stack<int> s;
      bool ok = true;
      int a = 1, b = 1;
      while (b <= n) {
        if (a == target[b]) {
          a++; b++;
        } else if ((int) s.size() && s.top() == target[b]) {
          s.pop(); b++;
        } else if (a <= n) {
          s.push(a++);
        } else {
          ok = false;
          break;
        }
      }
      cout << (ok ? "Yes" : "No") << '\n';
    }
    cout << '\n';
  }
  return 0;
}
