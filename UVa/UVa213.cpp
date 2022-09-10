#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int a[8][1 << 8];
  auto readchar = [&]() {
    while (true) {
      int ch = getchar();
      if (ch != '\n' && ch != '\r') {
        return ch;
      }
    }
  };
  auto readint = [&](int c) {
    int v = 0;
    while (c--) {
      v = v * 2 + (readchar() - '0');
    }
    return v;
  };
  auto readcode = [&]() {
    memset(a, 0, sizeof(a));
    a[1][0] = readchar();
    for (int len = 2; len < 8; len++) {
      for (int i = 0; i < (1 << len) - 1; i++) {
        int ch = getchar();
        if (ch == EOF) return false;
        if (ch == '\n' || ch == '\r') return true;
        a[len][i] = ch;
      }
    }
    return true;
  };
  while (readcode()) {
    while (true) {
      int len = readint(3);
      if (len == 0) break;
      while (true) {
        int v = readint(len);
        if (v == (1 << len) - 1) break;
        putchar(a[len][v]);
      }
    }
    putchar('\n');
  }
  return 0;
}
