#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  string foo;
  getline(cin, foo);
  while (tt--) {
    vector<string> buf;
    while (true) {
      string s;
      getline(cin, s);
      if (s[0] == '#') {
        break;
      } else {
        buf.push_back(s);
      }
    }
    int n = (int) buf.size();
    function<void(int, int)> dfs = [&](int r, int c) {
      cout << buf[r][c] << '(';
      if (r + 1 < n && buf[r + 1][c] == '|') {
        int i = c;
        while (i - 1 >= 0 && buf[r + 2][i - 1] == '-') {
          --i;
        }
        while (buf[r + 2][i] == '-' && buf[r + 3][i] != '\0') {
          if (!isspace(buf[r + 3][i])) {
            dfs(r + 3, i);
          }
          ++i;
        }
      }
      cout << ')';
    };
    cout << '(';
    if (n) {
      for (int i = 0; i < (int) buf[0].length(); i++) {
        if (buf[0][i] != ' ') {
          dfs(0, i);
          break;
        }
      }
    }
    cout << ")\n";
  }
  return 0;
}
