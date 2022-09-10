/**
 *    author:  willy
 *    created: Tue, 02 Nov 2021 15:31:20 GMT
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  const int MAX = (int) 1e6;
  vector<int> has(MAX + 1, 0);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    has[x]++;
  }
  bool found = false;
  for (int gcd = MAX; gcd >= 1; gcd--) {
    int be = 0;
    for (int i = gcd; i <= MAX; i += gcd) {
      be += has[i];
      if (be >= 2) {
        cout << gcd << '\n';
        found = true;
        break;
      }
    }
    if (found) {
      break;
    }
  }
  return 0;
}
