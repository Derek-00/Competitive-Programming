/**
 *    author:  willy
 *    created: Tue, 07 Dec 2021 02:27:29 GMT
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<bool> win(k + 1, false);
  for (int i = 0; i <= k; i++) {
    for (int j = 0; j < n; j++) {
      if (i - a[j] >= 0 && !win[i - a[j]]) {
        win[i] = true;
        break;
      }
    }
  }
  cout << (win[k] ? "First" : "Second") << '\n';
  return 0;
}
