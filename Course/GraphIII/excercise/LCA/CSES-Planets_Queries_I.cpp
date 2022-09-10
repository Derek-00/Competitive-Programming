/**
 *    author:  willy
 *    created: Fri, 01 Oct 2021 15:19:45 GMT
**/
#include <bits/stdc++.h>

using namespace std;

// problem URL: https://cses.fi/problemset/task/1750/

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  // note: if setting vector::size is n, it'll be 2n!!!
  const int N = 200010;
  const int K = 30;
  array<array<int, K + 1>, N> pr;
  for (int i = 0; i < n; i++) {
    cin >> pr[i][0];
    --pr[i][0];
  }
  for (int j = 1; j <= K; j++) {
    for (int i = 0; i < n; i++) {
      pr[i][j] = pr[pr[i][j - 1]][j - 1];
    }
  }
  while (q--) {
    int x, k;
    cin >> x >> k;
    --x;
    for (int j = 0; j <= K; j++) {
      if ((1 << j) & k) {
        x = pr[x][j];
      }
    }
    cout << x + 1 << '\n';
  }
  return 0;
}
