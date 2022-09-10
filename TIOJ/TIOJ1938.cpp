/**
 *    author:  willy
 *    created: Mon, 13 Dec 2021 01:32:29 GMT
**/
#include <bits/stdc++.h>

using namespace std;

int m, n, a, b, c, d;

int dp[200][200][200];

int Solve(int x, int y, int n) {
  if (x < 0 || y < 0 || n < 0) {
    return 0;
  }
  if (dp[x][y][n] != 0) {
    return dp[x][y][n];
  }
  int amount = (a * n + b * x + c * y) % d;
  return dp[x][y][n] = max({Solve(x - 1, y - 1, n - 1) + amount, Solve(x - 1, y, n), Solve(x, y - 1, n)});
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  while (cin >> m >> n >> a >> b >> c >> d) {
    cout << Solve(m - 1, m - 1, n - 1) << '\n';
  }
  return 0;
}
