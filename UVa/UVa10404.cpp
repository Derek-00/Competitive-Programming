/**
 *    author:  willy
 *    created: Sat, 09 Oct 2021 18:13:05 GMT
**/
#include <bits/stdc++.h>

using namespace std;

// problem URL: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=114&page=show_problem&problem=1345

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  while (cin >> n) {
    int m;
    cin >> m;
    vector<int> a(m);
    for (int i = 0; i < m; i++) {
      cin >> a[i];
    }
    vector<bool> dp(n + 1, false);
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j < m; j++) {
        if (i >= a[j] && !dp[i - a[j]]) {
          dp[i] = true;
          break;
        }
      }
    }
    cout << (dp[n] ? "Stan" : "Ollie") << " wins" << '\n';
  }
  return 0;
}
