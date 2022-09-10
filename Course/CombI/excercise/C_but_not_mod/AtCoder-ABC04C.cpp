/**
 *    author:  willy
 *    created: Fri, 26 Nov 2021 19:33:53 GMT
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  vector<string> s(3);
  for (int i = 0; i < 3; i++) {
    cin >> s[i];
    reverse(s[i].begin(), s[i].end());
  }
  int ptr = 0;
  while (true) {
    if (s[ptr].empty()) {
      cout << (char) ('A' + ptr) << '\n';
      return 0;
    }
    int nxt = (int) (s[ptr].back() - 'a');
    s[ptr].pop_back();
    ptr = nxt;
  }
  return 0;
}
