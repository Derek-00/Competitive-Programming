/**
 *    author:  willy
 *    created: Wed, 20 Oct 2021 12:08:41 GMT
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  vector<vector<char>> g(n + 1, vector<char>(n + 1));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> g[i][j];
    }
  }
  vector<vector<int>> pref(n + 1, vector<int>(n + 1));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      pref[i][j] = (g[i][j] == '*') + pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1];
    }
  }
  while (q--) {
    int xa, ya, xb, yb;
    cin >> xa >> ya >> xb >> yb;
    cout << pref[xb][yb] - pref[xb][ya - 1] - pref[xa - 1][yb] + pref[xa - 1][ya - 1] << '\n';
  }
  return 0;
}
