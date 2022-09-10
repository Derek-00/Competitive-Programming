#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  int cnt = 0;
  for (int i = 0; i < (int) s.length(); i++) {
    if (isalpha(s[i])) {
      for (int l = 0; l < (cnt == 0 ? 1 : cnt); l++) {
        cout << s[i];
      }
      cnt = 0;
    } else {
      int num = (int) (s[i] - '0');
      if (cnt == 0) {
        cnt = num;
      } else {
        cnt = cnt * 10 + num;
      }
    }
  }
  return 0;
}
