#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  const int maxd = 100;
  const int big = 10000;
  int kase = 0;
  int r, c;
  int d[maxd][maxd], d2[maxd][maxd], ans[maxd][maxd];
  bool cols[maxd];
  auto copy = [&](char type, int p, int q) {
    if (type == 'R') {
      for (int i = 1; i <= c; i++) {
        d[p][i] = d2[q][i];
      }
    } else {
      for (int i = 1; i <= r; i++) {
        d[i][p] = d2[i][q];
      }
    }
  };
  auto del = [&](char type) {
    memcpy(d2, d, sizeof(d));
    int cnt = (type == 'R' ? r : c);
    int counter = 0;
    for (int i = 1; i <= cnt; i++) {
      if (cols[i] == false) {
        copy(type, ++counter, i);
      }
    }
    if (type == 'R') {
      r = counter;
    } else {
      c = counter;
    }
  };
  auto ins = [&](char type) {
    memcpy(d2, d, sizeof(d));
    int cnt = (type == 'R' ? r : c);
    int counter = 0;
    for (int i = 1; i <= cnt; i++) {
      if (cols[i] == true) {
        copy(type, ++counter, 0);
      }
      copy(type, ++counter, i);
    }
    if (type == 'R') {
      r = counter;
    } else {
      c = counter;
    }
  };
  while (cin >> r >> c && r && c) {
    memset(d, 0, sizeof(d));
    for (int i = 1; i <= r; i++) {
      for (int j = 1; j <= c; j++) {
        d[i][j] = i * big + j;
      }
    }
    int n;
    cin >> n;
    while (n--) {
      memset(cols, false, sizeof(cols));
      string cmd;
      cin >> cmd;
      if (cmd == "EX") {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        swap(d[r1][c1], d[r2][c2]);
      } else {
        int a;
        cin >> a;
        while (a--) {
          int s;
          cin >> s;
          cols[s] = true;
        }
        if (cmd[0] == 'D') {
          del(cmd[1]);
        } else {
          ins(cmd[1]);
        }
      }
    }
    memset(ans, 0, sizeof(ans));
    for (int i = 1; i <= r; i++) {
      for (int j = 1; j <= c; j++) {
        ans[d[i][j] / big][d[i][j] % big] = i * big + j;
      }
    }
    if (kase > 0) {
      cout << '\n';
    }
    cout << "Spreadsheet #" << ++kase << '\n';
    int a;
    cin >> a;
    while (a--) {
      int r1, c1;
      cin >> r1 >> c1;
      cout << "Cell data in (" << r1 << ',' << c1 << ')';
      if (ans[r1][c1] == 0) {
        cout << " GONE\n";
      } else {
        cout << " moved to (" << ans[r1][c1] / big << ',' << ans[r1][c1] % big << ")\n";
      }
    }
  }
  return 0;
}
