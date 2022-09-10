#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  const int maxcol = 60;
  auto print = [&](const string s, int len) {
    cout << s;
    for (int i = 0; i < len - (int) s.length(); i++) {
      cout << ' ';
    }
  };
  int n;
  while (cin >> n) {
    vector<string> filename(n);
    int mx = 0;
    for (int i = 0; i < n; i++) {
      cin >> filename[i];
      mx = max(mx, (int) filename[i].length());
    }
    int cols = (maxcol - mx) / (mx + 2) + 1;
    int rows = (n - 1) / cols + 1;
    for (int i = 0; i < maxcol; i++) {
      cout << '-';
    }
    cout << '\n';
    sort(filename.begin(), filename.end());
    for (int r = 0; r < rows; r++) {
      for (int c = 0; c < cols; c++) {
        int idx = c * rows + r;
        if (idx < n) print(filename[idx], (c == cols - 1 ? mx : mx + 2));
      }
      cout << '\n';
    }
  }
  return 0;
}
