/**
 *    author:  willy
 *    created: Sat, 06 Nov 2021 15:30:54 GMT
**/
#include <iostream>

using namespace std;

const int N = 21;

long long dp[N][N];

long long dfs(int x, int y) {
  if (dp[x][y] != 0) {
    return dp[x][y];
  }
  if (x == 0 || y == 0) {
    return dp[x][y] = 1;
  }
  return dp[x][y] = dfs(x - 1, y) + dfs(x, y - 1);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int x, y;
    cin >> x >> y;
    --x; --y;
    cout << dfs(x, y) << '\n';
  }
  return 0;
}
