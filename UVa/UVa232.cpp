#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int counter = 1;
  while (true) {
    int r, c;
    cin >> r;
    if (r == 0) return 0;
    cin >> c;
    vector<vector<char>> a(r, vector<char> (c));
    vector<pair<int, int>> number;
    for (int i = 0; i < r; i++) {
      for (int l = 0; l < c; l++) {
        cin >> a[i][l];
      }
    }
    for (int i = 0; i < r; i++) {
      for (int l = 0; l < c; l++) {
        if (a[i][l] == '*') {
          continue;
        } else if (i == 0 || l == 0) {
          number.push_back({i, l});
        } else if (i >= 1 && a[i - 1][l] == '*') {
          number.push_back({i, l});
        } else if (l >= 1 && a[i][l - 1] == '*') {
          number.push_back({i, l});
        }
      }
    }
    if (counter > 1) {
      cout << '\n';
    }
    cout << "puzzle #" << counter++ << ":\n";
    cout << "Across\n";
    for (int i = 0; i < (int) number.size(); i++) {
      int x = number[i].first, y = number[i].second;
      if (y >= 1 && a[x][y - 1] != '*') {
        continue;
      }
      cout << setw(3) << i + 1 << '.';
      for (int l = y; l < c; l++) {
        if (a[x][l] == '*') {
          break;
        }
        cout << a[x][l];
      }
      cout << '\n';
    }
    cout << "Down\n";
    for (int i = 0; i < (int) number.size(); i++) {
      int x = number[i].first, y = number[i].second;
      if (x >= 1 && a[x - 1][y] != '*') {
        continue;
      }
      cout << setw(3) << i + 1 << '.';
      for (int l = x; l < r; l++) {
        if (a[l][y] == '*') {
          break;
        }
        cout << a[l][y];
      }
      cout << '\n';
    }
  }
  return 0;
}
