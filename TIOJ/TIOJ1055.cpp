/**
 *    author:  willy
 *    created: Sun, 08 Aug 2021 12:55:06 GMT
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int a, b;
  cin >> a >> b;
  if (a < b) {
    for (int i = a; i <= b; i++) {
      for (int j = 0; j < i; j++) {
        cout << '*';
      }
      cout << '\n';
    }
  } else {
    for (int i = a; i >= b; i--) {
      for (int j = 0; j < i; j++) {
        cout << '*';
      }
      cout << '\n';
    }
  }
  return 0;
}
