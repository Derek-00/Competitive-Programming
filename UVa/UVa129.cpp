/**
 *    author:  willy
 *    created: Fri, 20 Aug 2021 03:16:55 GMT
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 123;

int n, l;
int cnt;
int s[N];

bool dfs(int cur) {
  if (cnt++ == n) {
    for (int i = 0; i < cur; i++) {
      if (i % 64 == 0 && i > 0) {
        cout << '\n';
      } else {
        if (i % 4 == 0 && i > 0) {
          cout << " ";
        }
      }
      cout << (char) ('A' + s[i]);
    }
    cout << '\n' << cur << '\n';
    return false;
  }
  for (int i = 0; i < l; i++) {
    s[cur] = i;
    bool ok = true;
    for (int j = 1; j * 2 <= cur + 1; j++) {
      bool equal = true;
      for (int k = 0; k < j; k++) {
        if (s[cur - k] != s[cur - k - j]) {
          equal = false;
          break;
        }
      }
      if (equal) {
        ok = false;
        break;
      }
    }
    if (ok && !dfs(cur + 1)) {
      return false;
    }
  }
  return true;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  while (cin >> n >> l) {
    if (n == 0 && l == 0) {
      break;
    }
    cnt = 0;
    dfs(0);
  }
  return 0;
}
