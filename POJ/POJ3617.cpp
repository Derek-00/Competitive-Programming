/**
 *    author:  willy
 *    created: Mon, 02 Aug 2021 09:09:49 GMT
**/
#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<char> s(n);
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  int l = 0, r = n - 1;
  int cnt = 0;
  while (l <= r) {
    bool dir = true;
    for (int i = 0; i <= r - l; i++) {
      if (s[l + i] < s[r - i]) {
        break;
      }
      if (s[l + i] > s[r - i]) {
        dir = false;
        break;
      }
    }
    cout << (dir ? s[l++] : s[r--]);
    if (++cnt == 80) {
      cout << '\n';
      cnt = 0;
    }
  }
  return 0;
}
