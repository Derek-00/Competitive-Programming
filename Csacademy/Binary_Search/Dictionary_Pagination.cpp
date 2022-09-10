/**
 *    author:  willy
 *    created: Sat, 01 Jan 2022 10:08:40 GMT
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  vector<string> s(n);
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  sort(s.begin(), s.end());
  while (q--) {
    string w;
    int x;
    cin >> w >> x;
    int id = (int) (lower_bound(s.begin(), s.end(), w) - s.begin());
    cout << (id + x) / x << '\n';
  }
  return 0;
}
