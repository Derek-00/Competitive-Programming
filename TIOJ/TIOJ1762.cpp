/**
 *    author:  willy
 *    created: Tue, 10 Aug 2021 12:42:19 GMT
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m, r;
  cin >> n >> m >> r;
  vector<vector<int>> a(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    vector<int> b(m);
    for (int j = i; j < n; j++) {
      for (int k = 0; k < m; k++) {
        b[k] += a[j][k];
      }
      int ptr = 0;
      int total = 0;
      for (int k = 0; k < m; k++) {
        total += b[k];
        while (total > r) {
          total -= b[ptr++];
        }
        ans = max(ans, (j - i + 1) * (k - ptr + 1));
      }
    }
  }
  cout << ans << '\n';
  return 0;
}
