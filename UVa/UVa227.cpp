#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int counter = 1;
  while (true) {
    char a[10][10];
    gets(a[0]);
    if (a[0][0] == 'Z') {
      return 0;
    }
    if (strlen(a[0]) < 5) {
      a[0][4] = ' ';
    }
    for (int i = 1; i < 5; i++) {
      gets(a[i]);
      if (strlen(a[i]) < 5) {
        a[i][4] = ' ';
      }
    }
    int x, y;
    for (int i = 0; i < 5; i++) {
      for (int l = 0; l < 5; l++) {
        if (a[i][l] == ' ') {
          x = i; y = l;
          break;
        }
      }
    }
    bool illegal = false;
    while (true) {
      int s;
      s = getchar();
      if (s == '0') {
        break;
      }
      if (illegal) {
        continue;
      }
      if (s == '\n') {
        continue;
      }
      if (s == 'A' && x >= 1) {
        a[x][y] = a[x - 1][y];
        --x;
      } else if (s == 'B' && x < 4) {
        a[x][y] = a[x + 1][y];
        ++x;
      } else if (s == 'R' && y < 4) {
        a[x][y] = a[x][y + 1];
        ++y;
      } else if (s == 'L' && y >= 1) {
        a[x][y] = a[x][y - 1];
        --y;
      } else {
        illegal = true;
      }
    }
    getchar();
    a[x][y] = ' ';
    if (counter > 1) {
      cout << '\n';
    }
    cout << "Puzzle #" << counter++ << ":\n";
    if (illegal) {
      cout << "This puzzle has no final configuration.\n";
    } else {
      for (int i = 0; i < 5; i++) {
        for (int l = 0; l < 5; l++) {
          cout << a[i][l] << (l == 4 ? '\n' : ' ');
        }
      }
    }
  }
  return 0;
}
